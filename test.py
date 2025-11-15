async def main():
    paths = get_paths()

    setup_logging(paths)
    config = load_config(paths)
    retort = create_retort()
    file_storage = create_file_storage(config.file_storage_config)
    bot = create_bot(config)
    pool = create_pool(config.db)
    level_test_dao = create_level_test_dao()
    try:
        async with (
            pool() as session,
            create_redis(config.redis) as redis,
        ):
            dao = HolderDao(session, redis, level_test_dao)
            file_gateway = BotFileGateway(
                bot=bot,
                file_storage=file_storage,
                dao=dao.file_info,
                tech_chat_id=config.bot.log_chat,
            )
            bot_player = await dao.player.upsert_author_dummy()
            await dao.commit()
            ############ next is real main, all other was only dependencies setup
            await do_some_stuff(
                bot_player=bot_player,
                dao=dao,
                file_gateway=file_gateway,
                retort=retort,
                path=config.file_storage_config.path,
            )
    finally:
        await bot.session.close()
        close_all_sessions()
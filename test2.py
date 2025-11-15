async def main():
    paths = common_get_paths()

    setup_logging(paths)
    dishka = make_async_container(
        *get_providers(paths),
    )
    try:
        config = await dishka.get(TgBotConfig)
        dao = await dishka.get(HolderDao)
        bot_player = await dao.player.upsert_author_dummy()
        await dao.commit()
        await do_some_stuff(
            bot_player=bot_player,
            dao=dao,
            file_gateway=await dishka.get(FileGateway),
            retort=await dishka.get(Retort),
            path=config.file_storage_config.path.parent / "scn",
        )
    finally:
        await dishka.close()



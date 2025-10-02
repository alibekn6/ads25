#include <iostream>

struct FrequencyNode {
    int number;
    int count;
    FrequencyNode* next;

    FrequencyNode(int num) : number(num), count(1), next(nullptr) {}
};

struct ModeNode {
    int number;
    ModeNode* next;

    ModeNode(int num) : number(num), next(nullptr) {}
};

void insertSorted(ModeNode*& head, ModeNode* newNode) {
    if (head == nullptr || head->number < newNode->number) {
        newNode->next = head;
        head = newNode;
    } else {
        ModeNode* current = head;
        while (current->next != nullptr && current->next->number > newNode->number) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printModes(ModeNode* head) {
    ModeNode* current = head;
    while (current != nullptr) {
        std::cout << current->number;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteFrequencyList(FrequencyNode* head) {
    FrequencyNode* current = head;
    while (current != nullptr) {
        FrequencyNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void deleteModesList(ModeNode* head) {
    ModeNode* current = head;
    while (current != nullptr) {
        ModeNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    FrequencyNode* freqHead = nullptr;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        FrequencyNode* current = freqHead;
        bool found = false;
        while (current != nullptr) {
            if (current->number == num) {
                current->count++;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            FrequencyNode* newNode = new FrequencyNode(num);
            newNode->next = freqHead;
            freqHead = newNode;
        }
    }

    int maxFrequency = 0;
    if (freqHead != nullptr) {
        maxFrequency = freqHead->count;
        FrequencyNode* current = freqHead->next;
        while (current != nullptr) {
            if (current->count > maxFrequency) {
                maxFrequency = current->count;
            }
            current = current->next;
        }
    }

    ModeNode* modesHead = nullptr;
    FrequencyNode* currentFreq = freqHead;
    while (currentFreq != nullptr) {
        if (currentFreq->count == maxFrequency) {
            ModeNode* newMode = new ModeNode(currentFreq->number);
            insertSorted(modesHead, newMode);
        }
        currentFreq = currentFreq->next;
    }

    printModes(modesHead);

    deleteFrequencyList(freqHead);
    deleteModesList(modesHead);

    return 0;
}



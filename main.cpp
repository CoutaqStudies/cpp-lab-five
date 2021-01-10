#include "TaskOne.cpp"
#include "TaskTwo.cpp"
#include "TaskThreeAndFour.cpp"
#include "TaskFive.cpp"
#include "TaskSix/Source Files/TaskSix.cpp"
int main() {
    bool execute = true;
    while (execute){
        std::cout<<"\nSelect you warrior (1-6, anything else to exit):"<<std::endl;
        char task;
        std::cin>>task;
        switch (task) {
            case '1':
                TaskOne();
                break;
            case '2':
                TaskTwo();
                break;
            case '3':
            case '4':
                TaskThree();
                break;
            case '5':
                TaskFive();
                break;
            case '6':
                TaskSix();
                break;
            default:
                execute = false;
        }
    }

    return 0;
}

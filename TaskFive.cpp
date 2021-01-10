//
// Created by Michael on 10.01.2021.
//

void TaskFive(){
    Cache<std::string> stringCache;
    Cache<int> intCache;
    stringCache.add("this starts with t");
    std::cout<<stringCache.contains("d")<<std::endl;
    std::cout<<stringCache.contains("t")<<std::endl;
    for(int i = 0; i<=100; i++){
        intCache+=i;
        try{
            stringCache.add(std::to_string(i));
        } catch (std::exception &e) {
            std::cout<<"Caught exception of type "<<e.what()<<" at index "<<i<<std::endl;
        }
    }
    std::cout<<intCache.contains(314)<<std::endl;
    std::cout<<intCache.contains(10)<<std::endl;
}

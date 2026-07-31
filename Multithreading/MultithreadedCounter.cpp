#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

std::atomic<int> counter(0);
std::mutex mtx;
int MAX_COUNT = 100;
std::atomic<bool> stop_flag(false);

std::atomic<int> turn{0};

void helper(int t){
    int myTurn = t;
    
    while(true){
        if(counter >= MAX_COUNT){
            return;
        }
        while(turn.load(std::memory_order_acquire) != myTurn) {}
        
        counter+=1;
        std::cout<<myTurn<<".  "<<counter<<std::endl;
        
        int nextturn = (turn+1)%4;
        turn.store(nextturn, std::memory_order_release);
    }
}


int main(){

    std::vector<std::thread> thread_pool;
    for(int i=0; i<4; i++){
        thread_pool.emplace_back(helper, i);
    }

    for(int i=0; i<4; i++){
        if(thread_pool[i].joinable())
            thread_pool[i].join();
    }

}
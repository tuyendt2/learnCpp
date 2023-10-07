#include <iostream>
#include <cmath>
#include <future>

 
int main()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a, b); 
    });
    std::future<int> result = task.get_future();
                     
    task(2, 9);
                 
    std::cout << "task_lambda:\t" << result.get() << '\n';
	
	return 0;
}


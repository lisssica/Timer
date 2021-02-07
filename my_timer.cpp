#include <iostream>
#include <chrono>
#include <vector>

class Timer {

    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;

  private:

    std::vector<std::vector<time_point_t>> _intervals;
    bool _isActive = false;
    u_int16_t _currentInterval = 0;

  public:
    //constructor
    Timer() {
        Start();
    }

    ~Timer() {
        Stop();
    }

    void Start() {
        if (!_isActive) {
            std::vector<time_point_t> interval = {clock_t::now()};
            _intervals.push_back(interval);
            _currentInterval = _intervals.size() - 1;
            _isActive = true;
        }
    }

    void Pause() {
        if (_isActive) {
            _isActive = false;
            _intervals[_currentInterval].push_back(clock_t::now());
        }
    }

    void Lap() {
        if (_isActive) {
            _intervals[_currentInterval].push_back(clock_t::now());
        }
    }


    void Print() {
        int totalElapsedTime = 0;
        int currentLap = 0;

        for (auto interval = 0; interval < _intervals.size(); interval++) {
            for (auto innerLap = 1; innerLap < _intervals[interval].size(); innerLap++) {
                int currentInterval = std::chrono::duration_cast<std::chrono::milliseconds>
                                      (_intervals[interval][innerLap] - _intervals[interval][innerLap - 1]).count();
                totalElapsedTime += currentInterval;

                std::cout << "Lap " << currentLap << " time: " << currentInterval <<
                          " TotalTime: " << totalElapsedTime << std::endl;
                currentLap++;
            }

        }

        std::cout << std::endl;
        std::cout << "total elapsed time: " << totalElapsedTime << " ms" << std::endl;
    }
  private:
    void Stop() {
        if (_isActive) {
            _isActive = false;
            _intervals[_currentInterval].push_back(clock_t::now());
            Print();
        } else {
            Print();
        }
    }

};




int main() {

{
    Timer t1;
    std::vector<int> vector1(100000000, 0);
    t1.Lap();
    std::vector<int> vector2(100000000, 0);
    t1.Lap();
    std::vector<int> vector3(100000000, 0);
    t1.Pause();
    //delay
    std::vector<int> vector4(100000000, 0);
    t1.Start();
    std::vector<int> vector5(100000000, 0);
    t1.Lap();
    std::vector<int> vector6(100000000, 0);
    t1.Lap();
    std::vector<int> vector7(100000000, 0);

}

    std::vector<int> vector8(100000000, 0);


    return 0;
}
#include <gtest/gtest.h>
#include "stopwatch.h"
#include <thread>
#include <chrono>


void sleepMilliseconds(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


TEST(StopwatchTest, StartAndStop) {
    Stopwatch stopwatch;
    stopwatch.start();
    sleepMilliseconds(1000);
    stopwatch.stop();

    double seconds = stopwatch.get_seconds();
    EXPECT_NEAR(seconds, 1.0, 0.1);
}

TEST(StopwatchTest, Reset) {
    Stopwatch stopwatch;
    stopwatch.start();
    sleepMilliseconds(500);
    stopwatch.stop();
    stopwatch.reset();


    EXPECT_EQ(stopwatch.get_seconds(), 0);
}

TEST(StopwatchTest, TimeAfterStop) {
    Stopwatch stopwatch;
    stopwatch.start();
    sleepMilliseconds(500);
    stopwatch.stop();

    double secondsAfterStop = stopwatch.get_seconds();
    sleepMilliseconds(500);

    EXPECT_EQ(stopwatch.get_seconds(), secondsAfterStop);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

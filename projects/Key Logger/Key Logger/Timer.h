#pragma once

#ifndef _TIMER_H_
#define _TIMER_H_

#include <thread>
#include <chrono>

// this header is required for std::function<>
#include <functional>

class Timer {
	private:
		std::thread Thread;
		bool alive;
		// shows how many times a fucntion in called
		long call_number;
		// shows how many times a fucntion is to be called
		long repeat_count;
		// represents interval between function calls
		std::chrono::milliseconds interval;

		std::function<void(void)> funct;

		void SleepAndRun() {
			std::this_thread::sleep_for(interval);
			if (this->alive) {
				Function()();
			}
		}

		void ThreadFunc() {
			if (this->call_number == Timer::Infinite)
				while (this->alive)
					this->SleepAndRun();
			else
				while (this->repeat_count--)
					this->SleepAndRun();
		}

	public:
		static const long Infinite = -1L;

		Timer() {
			this->alive = false;
			this->call_number = -1L;
			this->repeat_count = -1L;
			this->interval = std::chrono::milliseconds(0);
			this->funct = nullptr;
		}

		Timer(const std::function<void(void)>& f) {
			this->alive = false;
			this->call_number = -1L;
			this->repeat_count = -1L;
			this->interval = std::chrono::milliseconds(0);
			this->funct = f;
		}

		Timer(const std::function<void(void)>& f, const unsigned long& i,
			const long repeat = Timer::Infinite) {
			this->alive = false;
			this->call_number = repeat;
			this->interval = std::chrono::milliseconds(i);
			this->funct = f;
		}

		void Start(bool Async = true) {
			if (IsAlive())
				return;
			this->alive = true;
			this->repeat_count = call_number;
			if (Async)
				this->Thread = std::thread(&Timer::ThreadFunc, this);
			else
				this->ThreadFunc();
		}

		void Stop() {
			this->alive = false;
			this->Thread.join();
		}

		void SetFunction(const std::function<void(void)>& f) {
			this->funct = f;
		}

		bool IsAlive() const {
			return this->alive;
		}

		void RepeatCount(const long r) {
			if (this->alive)
				return;
			this->call_number = r;
		}

		long GetLeftCount() const {
			return this->repeat_count;
		}

		long GetRepeatCount() const {
			return this->call_number;
		}

		void SetInterval(const unsigned long& i) {
			if (this->alive)
				return;
			this->interval = std::chrono::milliseconds(i);
		}

		unsigned long Interval() const {
			return this->interval.count();
		}

		const std::function<void(void)>& Function() const {
			return this->funct;
		}
};

#endif // _TIMER_H_
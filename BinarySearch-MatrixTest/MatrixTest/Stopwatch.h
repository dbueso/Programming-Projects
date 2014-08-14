// Stopwatch.h
// ---
// Stopwatch class for directly measuring time complexity of code.

// Instructions
// ---
// Create a Stopwatch object and start() it:

// Stopwatch a;
// a.start();

// OR

// Stopwatch a(1);

// The following actions are also available:

// reset() - set time to 0
// stop() - pause countup
// ms() - get time in MILLISECONDS
// sec() - " in SECONDS
// min() - " in MINUTES

// The same watch can be started and stopped multiple times, only logging the
// intervals in-between.

#include <ctime>

using namespace std;

struct Stopwatch
{
	// Constructors

	Stopwatch() : stopped(true), time(0.0) {}
	Stopwatch(bool start) : stopped(true), time(0.0)
	{
		if (start) this->start();
	}

	// Utilities

	void start()
	{
		if (!stopped) return;
		last = clock();
		stopped = false;
	}
	void stop()
	{
		if (stopped) return;
		clock_t now = clock();
		time += double (now - last) / CLOCKS_PER_SEC;
		last = now;
		stopped = true;
	}
	void reset()
	{
		if (!stopped) last = clock();
		time = 0.0;
	}

	double ms()
	{
		return sec() * 1000;
	}
	double sec()
	{
		if (stopped) return time;
		clock_t now = clock();
		return time += double (now - last) / CLOCKS_PER_SEC;
	}
	double min()
	{
		return sec() / 60;
	}

private:
	// Data

	clock_t last;
	bool stopped;
	double time;
};

/*NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNN                                               NNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNN     Jess Yarbrough * jly3833@cse.tamu.edu     NNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNN                                               NNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNN         NNNNNNNNNN         NNNNNNNNNI         NNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN         NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN         NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNN         NNNNNNNNNN         NNN       DNNNNNNN       NNNNNNNNNND
NNNNNNNNNNNNNNNNDO      NNNNNNNNNNN         NNNM$       NNNN=       NDNNNNNNNNND
NNNNNNNNNNNNNNNNN        NNNNNNNNNN         NNNNO       ZNNN        NNNNNNNNNNND
NNNNNNNNNNNNNNNN          NNNNNNNNN         NNNNO        DD         NNNNNNNNNNND
NNNNNNNNNNNNNNN7    NN    DNNNNNNNN         NNNNO                   NNNNNNNNNNND
NNNNNNNNNNNNNNN    7NN:    NNNNNNNN         NNNNO    N        N     NNNNNNNNNNND
NNNNNNNNNNNNND              NNNNNNN         NNNNO    NN      NN     NNNNNNNNNNND
NNNNNNNNNNNNN:              $NNNNNN         NNNNO    NNN     NN     NNNNNNNNNNND
NNNNNNNNNNNND    NNNNNNN7    NNNNNN         NNNNO    NNN    NNN     NNNNNNNNNNND
NNNNNNNNNDDN     NNNNNNNN     DDNNN         NNND$    NDNN  NNND     DNNNNNNNNNND
NNNNNNNNNN        NNNNNN        NNN         NNN       ZNNNNNNN       NNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN         NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNDNNNN         NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNN                   NNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNN                   NNNNNNNNNNNNNNNNNNNNNNNNNNNNNND
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN*/

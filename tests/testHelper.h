/*
 * G. Hemingway @2016
 */
#ifndef _TESTHELPER_H_
#define _TESTHELPER_H_

#include <fstream>

//#define GRADUATE

/**
 *  Given a test vector and a correct vector, this function will check if the
 *  two vectors are the same, up to some tolerance level. If the test fails,
 *  abort() is called.
 */
inline void assertVector(const vector2 &test, const vector2 &correct, double fault = 0.00001) {
    EXPECT_NEAR((correct - test).norm(), 0.0, fault);
}

/**
 *  A helper method for creating 2 dimensional vectors.
 */
inline vector2 makeVector2(double x = 0, double y = 0) {
    vector2 v;
    v[0] = x;
    v[1] = y;
    return v;
}

/**
 *  A struct that will close an ifstream.
 */
struct FileCloser {
    FileCloser(std::ifstream &f) : file_(f) {}

    ~FileCloser() {
        file_.close();
    }

private:
    std::ifstream& file_;
};

#endif

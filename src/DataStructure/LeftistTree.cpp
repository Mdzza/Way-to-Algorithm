// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "LeftistTree.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

#define TEST_MAX 1024

auto Greater(Node *a, Node *b) -> int {
  return b->index - a->index;
}
auto Less(Node *a, Node *b) -> int {
  return a->index - b->index;
}

auto main() -> int {
  for (int i = 0; i < MAX; i++) {
    LeftistTree *t = LeftistTreeNew(Greater);
    for (int j = 0; j < MAX; j++) {
      LeftistTreePush(t, j);
      assert(LeftistTreeTop(t) == j);
    }
    for (int j = MAX-1; j >= 0; j--) {
      assert(LeftistTreeTop(t) == j);
      LeftistTreePop(t);
    }
    LeftistTreeFree(t);
  }

  for (int i = 0; i < MAX; i++) {
    LeftistTree *t1 = LeftistTreeNew(Greater);
    LeftistTree *t2 = LeftistTreeNew(Greater);
    for (int j = 0; j < MAX; j++) {
      if (j % 2) {
        LeftistTreePush(t1, j);
      } else {
        LeftistTreePush(t2, j);
      }
    }
    LeftistTree *t = LeftistTreeMerge(t1, t2);
    for (int j = MAX-1; j >= 0; j--) {
      assert(LeftistTreeTop(t) == j);
      LeftistTreePop(t);
    }
    LeftistTreeFree(t);
  }

  for (int i = 0; i < MAX; i++) {
    LeftistTree *t = LeftistTreeNew(Less);
    for (int j = 0; j < MAX; j++) {
      LeftistTreePush(t, j);
      assert(LeftistTreeTop(t) == 0);
    }
    for (int j = 0; j < MAX; j++) {
      assert(LeftistTreeTop(t) == j);
      LeftistTreePop(t);
    }
    LeftistTreeFree(t);
  }

  for (int i = 0; i < MAX; i++) {
    LeftistTree *t1 = LeftistTreeNew(Less);
    LeftistTree *t2 = LeftistTreeNew(Less);
    for (int j = 0; j < MAX; j++) {
      if (j % 2) {
        LeftistTreePush(t1, j);
      } else {
        LeftistTreePush(t2, j);
      }
    }
    LeftistTree *t = LeftistTreeMerge(t1, t2);
    for (int j = 0; j < MAX; j++) {
      assert(LeftistTreeTop(t) == j);
      LeftistTreePop(t);
    }
    LeftistTreeFree(t);
  }
  return 0;
}

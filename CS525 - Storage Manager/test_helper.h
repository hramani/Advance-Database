//
//  test_helper.h
//
//  Created by Kaushik Narayan, Kunal Dhande, Poojitha Duggappa, Hiral Ramani.
//  Copyright © 2016 Kaushik Narayan, Kunal Dhande, Poojitha Duggappa, Hiral Ramani. All rights reserved.

/*
 VERSION CONTROL
 
 ******************************************************************************************************
 *  File Name: test_helper.h
 *
 *  Description:
 *      Header file for Test Cases given in test_assign1_1.c file.
 *
 *
 *
 *  History:
 *      Date            Search String                           Content
 *      --------------- --------------------------------------- ----------------------
 *      06-02-2016      None                                    Used the "test_assign1_1.h" file from the CS
 *                                                              525 repository.
 *
 ******************************************************************************************************/


#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// var to store the current test's name
extern char *testName;

// short cut for test information
#define TEST_INFO  __FILE__, testName, __LINE__, __TIME__

// check the return code and exit if it's and error
#define TEST_CHECK(code)						\
  do {									\
    int rc_internal = (code);						\
    if (rc_internal != RC_OK)						\
      {									\
	char *message = errorMessage(rc_internal);			\
	printf("[%s-%s-L%i-%s] FAILED: Operation returned error: %s\n",TEST_INFO, message); \
	free(message);							\
	exit(1);							\
      }									\
  } while(0);

// check whether two strings are equal
#define ASSERT_EQUALS_STRING(expected,real,message)			\
  do {									\
    if (strcmp((expected),(real)) != 0)					\
      {									\
	printf("[%s-%s-L%i-%s] FAILED: expected <%s> but was <%s>: %s\n",TEST_INFO, expected, real, message); \
	exit(1);							\
      }									\
    printf("[%s-%s-L%i-%s] OK: expected <%s> and was <%s>: %s\n",TEST_INFO, expected, real, message); \
  } while(0)

// check whether two ints are equals
#define ASSERT_EQUALS_INT(expected,real,message)			\
  do {									\
    if ((expected) != (real))					\
      {									\
	printf("[%s-%s-L%i-%s] FAILED: expected <%i> but was <%i>: %s\n",TEST_INFO, expected, real, message); \
	exit(1);							\
      }									\
    printf("[%s-%s-L%i-%s] OK: expected <%i> and was <%i>: %s\n",TEST_INFO, expected, real, message); \
  } while(0)

// check whether two ints are equals
#define ASSERT_TRUE(real,message)					\
  do {									\
    if (!(real))							\
      {									\
	printf("[%s-%s-L%i-%s] FAILED: expected true: %s\n",TEST_INFO, message); \
	exit(1);							\
      }									\
    printf("[%s-%s-L%i-%s] OK: expected true: %s\n",TEST_INFO, message); \
  } while(0)


// check that a method returns an error code
#define ASSERT_ERROR(expected,message)		\
  do {									\
    int result = (expected);						\
    if (result == (RC_OK))						\
      {									\
	printf("[%s-%s-L%i-%s] FAILED: expected an error: %s\n",TEST_INFO, message); \
	exit(1);							\
      }									\
    printf("[%s-%s-L%i-%s] OK: expected an error and was RC <%i>: %s\n",TEST_INFO,  result , message); \
  } while(0)

// test worked
#define TEST_DONE()							\
  do {									\
    printf("[%s-%s-L%i-%s] OK: finished test\n\n",TEST_INFO); \
  } while (0)

#endif // TEST_HELPER_H

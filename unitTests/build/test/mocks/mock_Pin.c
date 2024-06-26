/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_Pin.h"

static const char* CMockString_Pin = "Pin";
static const char* CMockString_PinModuleInit = "PinModuleInit";
static const char* CMockString_PinWrite = "PinWrite";
static const char* CMockString_Value = "Value";

typedef struct _CMOCK_PinWrite_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  PinT Expected_Pin;
  unsigned char Expected_Value;

} CMOCK_PinWrite_CALL_INSTANCE;

typedef struct _CMOCK_PinModuleInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_PinModuleInit_CALL_INSTANCE;

static struct mock_PinInstance
{
  char PinWrite_IgnoreBool;
  char PinWrite_CallbackBool;
  CMOCK_PinWrite_CALLBACK PinWrite_CallbackFunctionPointer;
  int PinWrite_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE PinWrite_CallInstance;
  char PinModuleInit_IgnoreBool;
  char PinModuleInit_CallbackBool;
  CMOCK_PinModuleInit_CALLBACK PinModuleInit_CallbackFunctionPointer;
  int PinModuleInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE PinModuleInit_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_Pin_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.PinWrite_CallInstance;
  if (Mock.PinWrite_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_PinWrite);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.PinWrite_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.PinModuleInit_CallInstance;
  if (Mock.PinModuleInit_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_PinModuleInit);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.PinModuleInit_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_Pin_Init(void)
{
  mock_Pin_Destroy();
}

void mock_Pin_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void PinWrite(PinT Pin, unsigned char Value)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_PinWrite_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_PinWrite);
  cmock_call_instance = (CMOCK_PinWrite_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.PinWrite_CallInstance);
  Mock.PinWrite_CallInstance = CMock_Guts_MemNext(Mock.PinWrite_CallInstance);
  if (Mock.PinWrite_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.PinWrite_CallbackBool &&
      Mock.PinWrite_CallbackFunctionPointer != NULL)
  {
    Mock.PinWrite_CallbackFunctionPointer(Pin, Value, Mock.PinWrite_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_PinWrite,CMockString_Pin);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_Pin), (void*)(&Pin), sizeof(PinT), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_PinWrite,CMockString_Value);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_Value, Value, cmock_line, CMockStringMismatch);
  }
  if (Mock.PinWrite_CallbackFunctionPointer != NULL)
  {
    Mock.PinWrite_CallbackFunctionPointer(Pin, Value, Mock.PinWrite_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_PinWrite(CMOCK_PinWrite_CALL_INSTANCE* cmock_call_instance, PinT Pin, unsigned char Value);
void CMockExpectParameters_PinWrite(CMOCK_PinWrite_CALL_INSTANCE* cmock_call_instance, PinT Pin, unsigned char Value)
{
  memcpy((void*)(&cmock_call_instance->Expected_Pin), (void*)(&Pin),
         sizeof(PinT[sizeof(Pin) == sizeof(PinT) ? 1 : -1])); /* add PinT to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_Value = Value;
}

void PinWrite_CMockIgnore(void)
{
  Mock.PinWrite_IgnoreBool = (char)1;
}

void PinWrite_CMockStopIgnore(void)
{
  Mock.PinWrite_IgnoreBool = (char)0;
}

void PinWrite_CMockExpect(UNITY_LINE_TYPE cmock_line, PinT Pin, unsigned char Value)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_PinWrite_CALL_INSTANCE));
  CMOCK_PinWrite_CALL_INSTANCE* cmock_call_instance = (CMOCK_PinWrite_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.PinWrite_CallInstance = CMock_Guts_MemChain(Mock.PinWrite_CallInstance, cmock_guts_index);
  Mock.PinWrite_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_PinWrite(cmock_call_instance, Pin, Value);
}

void PinWrite_AddCallback(CMOCK_PinWrite_CALLBACK Callback)
{
  Mock.PinWrite_IgnoreBool = (char)0;
  Mock.PinWrite_CallbackBool = (char)1;
  Mock.PinWrite_CallbackFunctionPointer = Callback;
}

void PinWrite_Stub(CMOCK_PinWrite_CALLBACK Callback)
{
  Mock.PinWrite_IgnoreBool = (char)0;
  Mock.PinWrite_CallbackBool = (char)0;
  Mock.PinWrite_CallbackFunctionPointer = Callback;
}

void PinModuleInit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_PinModuleInit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_PinModuleInit);
  cmock_call_instance = (CMOCK_PinModuleInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.PinModuleInit_CallInstance);
  Mock.PinModuleInit_CallInstance = CMock_Guts_MemNext(Mock.PinModuleInit_CallInstance);
  if (Mock.PinModuleInit_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.PinModuleInit_CallbackBool &&
      Mock.PinModuleInit_CallbackFunctionPointer != NULL)
  {
    Mock.PinModuleInit_CallbackFunctionPointer(Mock.PinModuleInit_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.PinModuleInit_CallbackFunctionPointer != NULL)
  {
    Mock.PinModuleInit_CallbackFunctionPointer(Mock.PinModuleInit_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void PinModuleInit_CMockIgnore(void)
{
  Mock.PinModuleInit_IgnoreBool = (char)1;
}

void PinModuleInit_CMockStopIgnore(void)
{
  Mock.PinModuleInit_IgnoreBool = (char)0;
}

void PinModuleInit_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_PinModuleInit_CALL_INSTANCE));
  CMOCK_PinModuleInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_PinModuleInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.PinModuleInit_CallInstance = CMock_Guts_MemChain(Mock.PinModuleInit_CallInstance, cmock_guts_index);
  Mock.PinModuleInit_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void PinModuleInit_AddCallback(CMOCK_PinModuleInit_CALLBACK Callback)
{
  Mock.PinModuleInit_IgnoreBool = (char)0;
  Mock.PinModuleInit_CallbackBool = (char)1;
  Mock.PinModuleInit_CallbackFunctionPointer = Callback;
}

void PinModuleInit_Stub(CMOCK_PinModuleInit_CALLBACK Callback)
{
  Mock.PinModuleInit_IgnoreBool = (char)0;
  Mock.PinModuleInit_CallbackBool = (char)0;
  Mock.PinModuleInit_CallbackFunctionPointer = Callback;
}


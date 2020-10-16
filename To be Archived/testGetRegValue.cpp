
#include "stdafx.h"
#include <string>
#include "GetRegValue.h"

int _tmain(int argc, _TCHAR* argv[])
{
  std::string strValue = GetRegValue(2, "SOFTWARE\\360Safe\\Liveup", "mid");
  return 0;
}



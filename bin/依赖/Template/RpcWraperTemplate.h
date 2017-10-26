/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraper$Template$.h
* Author:       甘业清
* Description:  $ModCName$RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_$TEMPLATE$_H
#define __RPC_WRAPER_$TEMPLATE$_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "$Template$Rpc.pb.h"



//$ModCName$类的枚举定义
enum Const$Template$E
{
$DeclareMsgID$

};

$RpcClassWraper$

template<typename T> struct MessageIdT;
$DefMessageIdT$

#endif

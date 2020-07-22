//
//  log.h
//  Core
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef log_h
#define log_h

#define debugPrint(fmt, ...)    printf("[Debug]   ");printf(fmt, __VA_ARGS__); printf("\n")
#define warningPrint(fmt, ...)  printf("[Warning] ");printf(fmt, __VA_ARGS__); printf("\n")

#endif /* log_h */

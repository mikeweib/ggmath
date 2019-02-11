//
//  ggmath.h
//  ggmath
//
//  Created by Mike Wei on 2019/2/11.
//  Copyright © 2019 Mike Wei. All rights reserved.
//

#ifndef ggmath_h
#define ggmath_h

// 隐藏符号的设置
#ifdef GG_DEBUG
#define HIDDEN_API
#else
#define HIDDEN_API __attribute__ ((visibility ("hidden")))
#endif


#endif /* ggmath_h */

//防止同一个头文件被多次引用
#ifndef __ADD_H__  //ifndef--if not define ，如果没有定义过__ADD_H__，判定为真，运行下面的代码。如果定义过，则判定为假，不继续进行定义。
#define __ADD_H__
int Add(int, int);
#endif  //结束标志
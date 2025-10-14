//Q1.为什么C++有多种整型？
//A.为了适应不同的存储需求和计算需求，同时优化内存使用和性能。
//
//Q2.声明与下述描述相符的变量
//a.short 整数，值为80---short可以声明较小范围的整数
//b.unsigned int 整数，值为42110---unsigned int为无符号整数，可声明所有>=0的整数(较大的)
//c.值为3000000000的整数---这种超过22亿过大的数用long long定义比较合适
//
//Q3.C++提供了什么措施来防止超出整型的范围
//A.①对于无符号整型(unsigned int)溢出时规定发生环绕，即归零 ②提供多种整型类型(如int/unsigned int等)合理选用防止超出 
//  ③C++11引入的固定宽度整型(如std::int32_t和std::int64_t)可以显式选择具体位数的整数，从而避免溢出
//  ④可以手动设置std::numeric_limits的边界检查
//
//Q4.33L和33之间有什么区别？
//A.数据类型不同，33L是long类型，33是int类型。而且在64位系统33L可以存储更大的数字。
//
//Q5.char grade = 65 与 char grade = 'A'是否等价
//A.ASCII码值一致，都是65；但语法上不一样，65是整数，'A'是字符字面量。
//
//Q6.使用至少两种方法找出编码88表示的字符
//A.①通过static_cast<char>(88)显示转换类型 ②强制类型转换cout<<(char)88
//
//Q7.将long值赋给float变量会导致舍入误差，将long值赋给double变量呢？将long long值赋给double变量呢？
//A.有效数字位大小关系为float < long < long long < double , 所以long赋给float超出的部分会被舍弃，而long小于double所以赋值不会超出，不会导致舍入误差；
//同理long long 赋给double也不会，除非赋的值过大，所以通常情况下不会出现舍入误差。
//
//Q8.8 * 9 + 2 = 19; 6 * 3 / 4 = 4(/ 在整数之间计算取整); 3 / 4 * 6 = 0; 6.0 * 3 / 4 = 4.5(/ 在存在浮点数计算保留小数); 15 % 4 = 1(%取余数，且%仅适用于整数，存在浮点会报错)
//
//Q9.假设x1,x2是两个double变量，如何将它们作为整数相加再赋给整型变量？将它们作为double相加再转换为int呢？
//A.static_cast<int>(x1) + static_cast<int>(x2)即可；作为double相加则是static_cast<int>(x1 + x2)即可。static_cast<type>(变量名)具有强类型检查，编译时会检查转换是否合法，所以相较于直接加括号()不检查是否合法的转换更安全。
//
//Q10.指出声明变量类型：①auto cars = 15 (int) ②auto iou = 150.37_ (后缀_会被C++忽略，所以还是double) ③auto level = 'B' (char) ④auto crat = U'\U00002155' (char32_t，有8位数字故8 * 4，还有char16_t和char8_t，以此类推16有4个,而8一个也没有) 
//⑤auto fract = 8.25f / 2.5 (double，C++默认小数精度为double,而分子为float，然而存在double结果就会是double)

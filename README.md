# Hitman5_ExternalCheat
杀手5外部作弊程序


代码分析：
1.首先通过getProcId函数来进行遍历快照（使用函数参数的进程名称和系统所有快照的名称进行对比筛选出所需要的快照信息）之后可以获取到快照信息当中的ProcessID(进程ID)了。如果获取失败就进行弹窗通知。

2.使用获取到的进程ID调用OpenProcess函数来获得程序带有PROCESS_ALL_ACCESS权限的句柄。如果获取失败就进行弹窗通知。

3.获取到程序的所有权之后就可以获取程序的基础模块内存地址了（不是物理内存地址）。getModuleBase函数跟getProcId函数一样把对应程序的所有Module进行遍历，等找到跟参数对应的模块名称之后返回对应模块的基础地址。

4.因为游戏中的实际需要修改的地址基本都是通过某一个模块的基础地址加上一个偏移值来进行计算的，某些更深入的具体数值则需要通过好几级指针来进行访问。因此这里就需要定义一个findDMAAddy函数来解引多级指针。
  findDMAAddy函数主要是使用WindowsAPi当中的ReadProcessMemory函数来解指针，加上指针偏移值再for循环并返回最终值就可以解引多级指针了。
  
5.定位到具体地址之后可以使用WindowsAPI当中的WriteProcessMemory函数来修改想要修改的数值，因为修改内存中的数据需要先获取读写权限才能进行读写。这里可以使用WindowsAPI当中的VirtualProtectEx函数来修改指定地址的权限为PAGE_EXECUTE_READWRITE（可读写）。
  修改完毕之后通过WriteProcessMemory函数进行读写，为了避免权限问题或者规避简单的反作弊程序需要把权限改回原来的权限。因此再次调用VirtualProtectEx函数改回原来的访问权限。由于每次修改内存区域都需要进行繁琐的改权限操作因此可以定义一个新函数称为patchEx。
  patchEx函数把上面的繁琐操作进行了打包并设立成了单独的函数。
  
6.由于在一些作弊改游戏汇编代码操作中需要把某一大块内存地址修改成Nop指令，可以单独定义一个函数为nopEx。此函数主要是通过创建一个指向堆空间的指针再通过memset函数把堆空间中的所有内容改成汇编代码Nop（0x90），再利用之前定义的patchEx函数把目标地址填充为0x90。









Legal Disclaimer 法律声明

1. Purpose Limitation 使用目的限制
This project is intended **SOLELY** for the following purposes:  
本项目仅限用于以下用途：
- Academic research on software reverse engineering techniques  
  软件逆向工程技术学术研究
- Educational demonstration of memory analysis methods  
  内存分析方法的数学证明与教学演示
- Non-commercial study of game system design patterns  
  非商业性质的游戏系统设计模式研究

2. Copyright Notice 版权声明
All game-related assets including but not limited to:  
包含但不限于以下游戏相关资产：
- Game client binaries 游戏客户端二进制文件
- Original artwork/resources 原始美术资源
- Trademarked logos 注册商标标识
are property of their respective copyright holders.  
均归属其合法版权方所有。

3. User Responsibility 使用者责任
Any usage beyond the scope defined in Section 1 shall be deemed as:  
超出第1条定义范围的使用行为将被视为：
- Violation of the Digital Millennium Copyright Act (DMCA) in the US  
  违反美国《数字千年版权法案》(DMCA)
- Infringement of Copyright Law Article 47 in China  
  触犯中国《著作权法》第47条
- Breach of EU Directive 2001/29/EC in Europe  
  违背欧盟《2001/29/EC指令》

4. Technical Restrictions 技术限制
This repository EXPLICITLY EXCLUDES:  
本仓库明确不包含：
- Pre-modified game executables 预修改的游戏可执行文件
- Copyrighted resource files 受版权保护的资源文件
- Activation bypass mechanisms 激活验证绕过机制

5. Liability Exclusion 责任免除
The author shall not be liable for:  
作者不对以下情况承担责任：
- Damages caused by misuse of the code 代码滥用造成的损害
- Legal consequences from unauthorized modifications 未经授权的修改导致的法务后果
- Violation of EULAs by end users 终端用户违反最终用户许可协议(EULA)

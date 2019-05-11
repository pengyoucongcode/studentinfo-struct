# studentinfo-struct
## explain
* This program mainly realizes the creation, insertion, search, display and deletion of sequential tables.
* Specifically, read the student achievement information from the disk file scores.txt, and use the gradeList structure to create a sequence table of student type data nodes.
* And then insert three records into the linked list:
```
张兰， 85， 77， 92   // inserted as Article 7 record
王平， 92， 83,  79  // Insert as clause 2
冯文成，77，68， 80  // Insert as the last article
```
* Then search the gradeList, and follow the prompts to find any record and display it on the screen.
* search for gradeList, to find the achievements of "令狐冲" and "王平" and display them on the screen.
* Delete the score record of "岳不群" in gradeList.
* The results of the program run are as follows
```
张红 78 94 90
李丽君 65 73 82
成平 94 68 78
王伟 84 86 69
文锦春 74 92 60
林黛玉 66 83 70
付凌云 88 79 82
岳不群 90 82 93
令狐冲 81 77 97
温玉琪 95 84 68
胡建军 85 73 75
刘汉 90 87 89
秋昌平 83 71 74
秦敖天 96 92 95
方世杰 83 90 88
我是分割线=================
插入三条记录后，顺序表中的情况：
张红 78 94 90
王平 92 83 79
李丽君 65 73 82
成平 94 68 78
王伟 84 86 69
文锦春 74 92 60
林黛玉 66 83 70
张兰 85 77 92
付凌云 88 79 82
岳不群 90 82 93
令狐冲 81 77 97
温玉琪 95 84 68
胡建军 85 73 75
刘汉 90 87 89
秋昌平 83 71 74
秦敖天 96 92 95
冯文成 77 68 80
你想按下标搜索第几条记录：6
第6条记录为：文锦春 74 92 60
你想搜索关于谁的记录:令狐冲
令狐冲的记录为:令狐冲 81 77 97
你还想查询谁的记录，是则请输入名字，否请输入No
王平
王平的记录为:王平 92 83 79
你还想查询谁的记录，是则请输入名字，否请输入No
no
无此人记录！
你还想查询谁的记录，是则请输入名字，否请输入No
No
你想删除谁的记录:岳不群
已找到此人记录，是否确认要删除？yes/no:yes
张红 78 94 90
王平 92 83 79
李丽君 65 73 82
成平 94 68 78
王伟 84 86 69
文锦春 74 92 60
林黛玉 66 83 70
张兰 85 77 92
付凌云 88 79 82
令狐冲 81 77 97
温玉琪 95 84 68
胡建军 85 73 75
刘汉 90 87 89
秋昌平 83 71 74
秦敖天 96 92 95
冯文成 77 68 80
```
## Build Status
[![Build Status](https://dev.azure.com/2923616405/Edipyc-GitHub-Builds/_apis/build/status/pengyoucongcode.studentinfostruct?branchName=master)](https://dev.azure.com/2923616405/Edipyc-GitHub-Builds/_build/latest?definitionId=3&branchName=master)

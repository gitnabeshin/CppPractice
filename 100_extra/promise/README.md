# Compile & Run

```
nabeshin@iMacNabeshin promise % g++ -std=c++11 main.cpp
nabeshin@iMacNabeshin promise % ./a.out                
start.
main:[0]
    thread func start.
    func:[0], 0
main:[1]
    func:[1], 1
main:[2]
main:[3]
    func:[2], 3
main:[4]
main:[5]    func:[3], 6

main:[6]
    func:[4], 10
main:[7]
main:[8]
    func:[5], 15
main:[9]
    func:[6], 21
main func get value before join.
    func:[7], 28
    func:[8], 36
    func:[9], 45
45
main func join...
    func: finished. sum = 45
main func finished.
```
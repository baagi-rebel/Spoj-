t=int(input())
for _ in range(t):
    mod=10**9+7
    n=input()
    ans=0
    for i in n:
        ans=(ans*10)%(mod)
        ans+=int(i)
        ans=ans%(mod)
    ini=0
   
    main=[ans]
    while(ini<len(n)-1):
        current=main[-1]
        power=pow(10,len(n)-1,mod)
        ans=(current-power*int(n[ini])%(mod))%(mod)
        ans=(ans*10+int(n[ini]))%mod
        main.append(ans)
        ini+=1
    power=pow(10,len(n),mod)
    final_ans=0
    for i in range(len(main)):
        final_ans*=power
        final_ans=final_ans%mod
        final_ans+=main[i]
        final_ans=final_ans%mod
    print(final_ans)
        

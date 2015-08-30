aa="  hello  "
bb="hello"
if compare(aa,bb)<0 then
	 say "not equal aa<bb "
else if compare(aa,bb)>0 then
	 say " aa>bb "
else say " aa =bb "
tt=2
a.=0;
do i=1 to 10
  say " a.i is " i   a.i
end
a.i=a.i+1
say " a.i is " i   a.i

aaaaa: procedure expose a
 arg tt1
 say " ttt1111 " tt1
 t=0;
k=0;
say " in aaaaaaaaaaaaa   value of   a "  a
do j = 1 to 10 by 5
  do i=1 to 12  by 2
	t=t+1
	k=k+2
	if k>5 then
		leave  j
 end
end
say " k is " k
say "i is " i
say " t is " t

return k

procedure a2 expose a t,k,i
do zz = 1 to 10 by 5
	t=t+1
	k=k+2
		if k>7 then
	leave  zz
end

do y = 1 to 10 by 5
	t=t+1
	k=k+2
		if k>7 then
	leave  y
end
if i=1 then
 say i
say " k is  after second doto  " k
a=44
return zz




a2:procedure
sss=1;ddd=2;a1=5
a.1=0
k=a(zzz,ttt,lll);


say "ssss " sss " aaa "  ddd " lll " lll
say ' after ffff '  a.1
a.y.z.x = ( 12 + -(5 * (14 *97)/(100 - (3))/(12+2) * (99-(100-1) ) ) +-12)|| ahmad
say "a.y is " a.y.z.x


a: procedure  expose sss ,a.1,ddd
arg s,x,v;
a=s*100+x*10+v;v=12222;sss=12;ddd=12;
say ' in a procedure a.1 is ' a.1
xx2=bb()
RETURN a


bb:procedure expose a.1
a.1=a.1+1
say " in bbbbbbbbbbbbbbbbbbbbbbbb  a.1 is    " a.1
bb1()


bb1:procedure expose a.1
a.1=a.1+1
if a.1<14 then
	bb();
say " 111111 in bbbbbbbbbbbbbbbbbbbbbbbb  a.1 is    " a.1

return a.1

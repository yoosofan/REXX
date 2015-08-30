set confirm=off
del d:\out\*.obj
del d:\out\*.out
del d:\out\*.exe
del d:\out\*.err
set confirm=on
dir *.bak /on/w >>change.inf
del *.bak
del *.sym
del *.obj
del *.out
del *.err
del *.exe
del *.csm
del *.dsw
exit



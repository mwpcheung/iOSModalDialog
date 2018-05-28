# iOSModalDialog
ios ModalDialog ISDialog ISButton
# description
  API like windows MessageBox.
  iOS tweak call SpringBoard DoModalDialog using iTunesStore private API.
  Sometimes we need to block the system and pop the MessageBox so that the user must make a choice.
# iOS 越狱模态对话框
  通过注入itunesstored, 呼叫SpringBoard 弹出模态对话框。 
  模态对话框的缘故， run 函数会阻塞住当前线程。 哪怕是主线程被run 阻塞住，iOS 是不会报错的。 
  1. 比如itunesstored 弹出对话框让你必须点确认的选项，你会发现整个系统是僵住的。 
  2. 自己挂钩xpc 发送mach msg 同样可以让SpringBoard 弹出相应的模态对话框。

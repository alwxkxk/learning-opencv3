个人学习《Learning OpenCV 3》的例子代码，但使用的是opencv 4.6。

并不包含所有例子的代码，只有部分个人测试与尝试的代码。完整的代码可参考[Learning-OpenCV-3_examples](https://github.com/oreillymedia/Learning-OpenCV-3_examples)。

使用vs开发，须按[tutorial_windows_visual_studio_opencv](https://docs.opencv.org/4.6.0/dd/d6e/tutorial_windows_visual_studio_opencv.html)配置环境变量与IDE的配，，点击.sln文件即可打开。项目名以`chapter{x}-....`来命名。

图片统一放到images中，所以Debugging/Command Arguments配置成如`$(ProjectDir)\..\..\images\fruits.jpg`

## 文件列表简单说明
- canny-parameter-test canny算法两个阀值的测试
- chapter2-example2-1 第一个opencv程序，用于验证。
- chapter6-exercise1 基本的绘图API，线、矩形、圆形、英文字体等。
- chapter6-exercise2 灰阶图
- chapter6-exercise3 调用摄像头显示并计算显示FPS。
- chapter8-exercise1 读取视频，输出灰阶视频与描边视频(canny算法)。
- chapter10-sobel sobel函数
- chapter10-exercise1 blur函数
- chapter10-erode-dilate erode和dilate的opencv官方例子
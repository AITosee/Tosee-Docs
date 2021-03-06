.. _chapter_hardware_index:


硬件介绍 
================

简介
----------------
Sentry2视觉传感器采用先进的64位RISC-V神经网络处理器K210开发设计，集成多种先进的离线视觉处理算法，可以满足基本的视觉处理需求。
板载ESP8285-WiFi芯片，可以直接通过Arduino进行编程开发，实现云端图像识别，无线图传，AIoT物联网等应用。ESP8285可以作为K210的协处理器，无需外接主控也可进行AI编程的学习。

目前有2个版本：企业版（标识E）、消费版（标识C）。两个版本在硬件配置和算法上有所不同，以下文档若无特殊说明，按企业版进行介绍，开机后查看屏幕右下角标识进行区分。

应用领域:智能机器人、智能小车、创意设计、STEAM教育、创客比赛、智能玩具、AIoT物联网、学校课题设计

.. image:: images/sentry2_top_bot_view.png


**LED灯**：通过灯光不同的颜色可以反映出不同的识别结果，当设置为白光常亮时可以当作补光灯使用

**摄像头**：实时的采集图像数据，Sentry2提供了摄像头设置功能，可以调节图像缩放、白平衡、亮度、饱和度等参数，满足高阶玩家需求

**WiFi天线**：传感器板载ESP8285芯片，具有WiFi无线通信功能，可以实现云端图像识别，无线图传，AIoT物联网应用等功能

**K210处理器**：带有神经网络处理单元，双核64位RISC-V处理器，在MCU级别处理其中具有十分优秀的图像处理能力

**SD卡座**：支持Micro-SD（TF）卡，用于保存图片使用，（**注意：有些SD卡并不支持，仅支持SPI通讯方式，不支持SDIO功能**）

**USB**：板载USB-UART芯片，可以直接与电脑通信与控制，同时作为固件更新接口，（**注意：USB供电会通过通讯接口对外输出，二者不可同时供电**）

**LCD屏幕**：高清广视角的TFT-ISP彩色屏幕，带来小巧而优秀的图像显示效果，方便于算法调试

**摇杆按键**：可实现“上下左右中”的5个方向的控制，提供简单实用的UI交互

**复位按键**：可实现硬件复位，特殊情况下使用

**通讯接口**：图像处理数据与主控的交互接口，支持UART和I2C方式，可以在UI界面里设置



硬件参数
----------------

================    ================    ================    ================    ================
项目                 单位                 企业版E               消费版C               备注
================    ================    ================    ================    ================
工作电压              V                   3.3～5.0             3.3～5.0            通讯口与USB不可同时供电
工作电流              mA                  190                  150                5V供电，开启人脸算法时的典型值
尺寸                 mm                  40×32×12             40x32x12.5         不带外壳
重量                 g                   15                   15                 不带外壳
定位孔间距            mm                  32                   32
定位孔直径            mm                  3                    3
摄像头类型            NA                  CMOS                 CMOS
摄像头分辨率          像素                 500W                 200W
摄像头帧率            fps                 50                   25
镜头视场角            度°                 70                   68                  
屏幕类型              NA                 TFT-ISP高清屏        TFT-ISP高清屏                   
屏幕尺寸              英寸                1.3                  1.3            
屏幕分辨率            像素                 240×240             240x240                  
================    ================    ================    ================    ================


算法列表
----------------

算法详细介绍可参阅:
:ref:`算法介绍<chapter_vision_index>`
章节

================    ================================================    ================    ================================    ================================    ====================
算法ID               名称                                                 英文名称             企业版E                               消费版C                              简介                                                                                                                           
================    ================================================    ================    ================================    ================================    ====================
1                    :ref:`颜色识别<chapter_vision_color_index>`          Color               支持                                  支持                               最高可设置25个识别区域，返回每个区域中的颜色信息，如R，G，B值及分类标签
2                    :ref:`色块检测<chapter_vision_blob_index>`           Blob                支持                                  支持                                检测图像中是否有指定的色块，支持黑、白、红、绿、蓝、黄6种色块同时检测
3                    :ref:`标签识别<chapter_vision_apriltag_index>`       Apriltag            支持                                  支持                                支持16H5，25H9,36H11编码的Apriltag标签，可以同时识别最多25个图案
4                    :ref:`线条检测<chapter_vision_line_index>`           Line                支持                                  支持                                检测图像中的线条，返回两个端点坐标及倾斜角度，可支持1～5个线段检测
5                    :ref:`深度学习<chapter_vision_learning_index>`       Learning            支持（25个数据）                        支持（15个数据）                     对任意物体进行离线训练并进行识别，可存储25个模型数据
6                    :ref:`卡片识别<chapter_vision_card_index>`           Card                支持（交通、形状、数字）                  支持（仅交通）                       识别特制的卡片图案，包含10张交通卡片，9张形状卡片，10张数字卡片
7                    :ref:`人脸识别<chapter_vision_face_index>`           Face                支持（25个数据）                        支持（15个数据）                      检测与识别人脸，支持口罩检测，可存储25个模型数据
8                    :ref:`20类物体<chapter_vision_20class_index>`        20Class             支持                                  支持                                识别常见的20类物体，如猫、汽车等
9                    :ref:`二维码<chapter_vision_qrcode_index>`           QrCode              支持                                  无                                检测与识别简单的二维码
10                   :ref:`自定义<chapter_vision_custom_index>`           Custom              支持                                  支持                                支持用户自定义算法，运行在板载ESP8285-WiFi芯片内，如云端识图
11                   :ref:`运动物体<chapter_vision_motion_index>`          Motion             支持                                  无                                判断图像中是否有移动区域
================    ================================================    ================    ================================    ================================    ====================


开发平台与驱动库
----------------

================================================    ================================    ================================    ========================================================================================================    ================    ================
开发平台                                              编程语言                             主控设备                            驱动库链接                                                                                                       企业版              消费版
================================================    ================================    ================================    ========================================================================================================    ================    ================
:ref:`Arduino<chapter_arduino_index>`               C/C++                                Arduino                            https://github.com/AITosee/Sentry-Arduino/releases                                                             支持                支持
:ref:`MakeCode<chapter_makecode_index>`             图形化                               Micro:bit                           https://github.com/AITosee/pxt-sentry/releases                                                                  支持                支持
:ref:`Mind+<chapter_mindplus_index>`                图形化，C/C++，MicroPython            Arduino、Micro:bit、掌控板             https://github.com/AITosee/ext-sentry/releases                                                                支持                支持
:ref:`Mixly<chapter_mixly_index>`                   图形化                                Arduino                             https://github.com/AITosee/Sentry-Mixly/releases                                                               支持                支持
:ref:`BXY<chapter_micropython_index>`               MicroPython                          Micro:bit、掌控板                    https://github.com/AITosee/Sentry-microPython/releases                                                         支持                支持
ARM PC                                              C/C++                               树莓派，Linux                        :download:`Sentry-Arduino-1.2.4_for_linux.zip <../Download/libs/Sentry-Arduino-1.2.4_for_linux.zip>`          支持                支持
================================================    ================================    ================================    ========================================================================================================    ================    ================

使用说明
----------------
Sentry2视觉传感器可以通过通讯接口与主控制器相连接，也可以通过USB与电脑连接。通讯接口可以在UI界面中配置为UART串口或I2C模式，还可以修改设备地址和波特率等参数。

驱动库、固件、资料手册、第三方资源等可参阅:
:ref:`资源下载<chapter_download_index>`
章节

**注意：USB与通讯接口不可以同时供电！！！**

连接主控
************************

接口定义
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: images/sentry2_output_port_info.png

================    ================    ================    ================
引脚序号              UART模式            I2C模式              备注
================    ================    ================    ================
1                   RX                  SDA
2                   TX                  SCL
3                   GND                 GND
4                   VCC                 VCC                 注意！！！当插入USB时，此端口可以对外部设备进行供电，此端口不可直接连接电池，当插入USB时不可接入3.3V系统，需要断开供电引脚
================    ================    ================    ================

接线方式
************************
以Arduino UNO举例说明

**UART模式**

.. image:: images/sentry2_connection_arduino_uart.png

**注意：UART模式下，视觉传感器的RX需要接Arduino的TX，传感器的TX接Arduino的RX**

**注意：如果使用软串口，可以指定其他的IO口，详见Arduino中的SoftSerialExample**

**注意：由于Arduino的RX和TX与烧录固件共用端口，因此在烧录程序时，需要断开RX，TX接线，推荐使用I2C或软串口模式**


**I2C模式**

.. image:: images/sentry2_connection_arduino_i2c.png

UI界面
************************

Sentry2视觉传感器具有2种UI界面：运行界面、设置界面

.. image:: images/run_view_and_ui_info.png

* 运行界面

    **算法状态**:此区域用于显示当前正在运行的算法

    **图像区域**:显示摄像头的图像

    **显示元素**:对被测物体进行标识，包括检测框、坐标、信息

    **系统状态**:显示当前帧率和当前图像缩放变焦值


* 设置界面

    **菜单选项**:上下拨动摇杆来选择不同的菜单，垂直短按摇杆可以进入相应的设置页面 

    **版本信息**:此处可以查看固件版本号和固件发布日期 

    **简介说明**:对当前菜单进行介绍说明 

    **控件按钮**:各种交互按键，用于进行设置操作，不同菜单下的控件是不同的，当导航键移动到某个控件上时会进行高亮显示或蓝边显示

    **操作提示**:当摇杆悬停到不同的控件上时，会显示相应的介绍信息或操作说明，相当于说明书的作用


UI设置界面
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: images/ui_3_pages.png

运行界面往右拨动摇杆可以进入UI设置界面，UI设置共有三个页面：算法设置、摄像头设置、硬件设置 

依次往左拨动摇杆则会逐次退出页面，直至返回运行界面

    **算法设置**:可以开启或关闭算法，配置算法参数 

    **摄像头设置**:用于调整摄像头的参数，可以对图像进行缩放、白平衡、饱和度、亮度、对比度等参数进行精细调节，需要具备一定的摄像头调参基础，适用于高阶玩家 

    **硬件设置**:用于配置通讯方式、波特率、设备地址、灯光颜色、语言等参数，以适配不同的使用模式 

硬件设置
************************

摇杆按键功能定义
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
上电开机后便可以通过摇杆对视觉传感器进行操作，传感器采用5向导航摇杆，操作定义如下表所示：

================    ================    ================
当前模式              操作方式              动作含义          
================    ================    ================
运行模式              向上拨动              切换上个算法
运行模式              向下拨动              切换下个算法
运行模式              向左拨动              拍照（当插入SD时）
运行模式              向右拨动              进入GUI设置模式
运行模式              垂直短按              保存当前模型（部分算法有效）
运行模式              向上长按              放大镜头焦距Zoom
运行模式              向下长按              缩小镜头焦距Zoom
运行模式              向左长按              关闭/开启屏幕
运行模式              垂直长按              删除所有保存的模型（部分算法有效）
...
设置模式              向上拨动              切换上一个菜单或控件
设置模式              向下拨动              切换下一个菜单或控件
设置模式              向左拨动              切换上一个设置界面/返回运行模式
设置模式              向右拨动              切换下一个设置界面
设置模式              垂直短按              进入控件进行参数设置
...
开机时                向上长按10秒          重置传感器
开机时                垂直长按              进入K210固件烧录模式
开机时                向下长按              进入ESP8285固件烧录模式
================    ================    ================

*提示：拨动即为短按，长按需要至少为2秒以上的保持时间后再松开*


设置通讯方式
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

用于设置视觉传感器与主控的通讯方式，设置后会自动保存，下次开机后不必再次设置，但当通讯异常时，需要检查这些参数是否被改变，有时固件更新后或调用了某些复位寄存器后会改变这些设置，此时需要重新设置

.. image:: images/sentry2_set_output_mode.png 

1. 在运行界面往右拨动3次摇杆，进入硬件设置界面
 
2. 在“输出模式”选项上，压按摇杆进入设置
 
3. 选择”UART“或”I2C“模式，一般来说，如果主控的UART端口无法支持高波特率，那么I2C的读取速度会更快，有利于提高图像处理帧率

4. 如果使用“UART模式”，那么还需要选择“标准指令”协议或“简单指令“协议，标准指令需要配合寄存器和驱动库进行开发，而简单指令只需要通过串口发送字符即可
 
5. 点击”确认“返回到菜单栏 

6. 往下拨动摇杆，切换到”设备地址“菜单 
 
7. 查看设备地址,此地址应与主控代码中的保持一致,压按摇杆可以进入设置，地址可设置为”0x60～0x63“， 点击”确认“并返回 

8. 如果选择”UART模式“，则还需要往下拨动摇杆，切换到”串口波特率“菜单 

9. 压按摇杆进入设置，左右拨动摇杆来设置波特率，支持“9600、19200、38400、57600、115200、921600、1152000、2000000”波特率，较高的波特率将有利于图像识别帧率的提升，不同的主控可支持的最高波特率有所差异，需要查看主控的相关说明，当通讯异常时，可尝试降低波特率，默认为9600

10. 往左拨动3次摇杆，返回至运行界面

设置USB功能
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sentry2板载一个USB端口，可以实现与电脑的交互通讯，其波特率可单独设置，数据通信方式基于“标准协议指令”或“简单协议指令”

.. image:: images/sentry2_set_usb.png 

**波特率**：支持“9600、19200、38400、57600、115200、921600、1152000、2000000”波特率，当控件位于最左侧时可以关闭usb功能

**至UART**：开启或关闭USB与UART的数据透传功能，开启后，可以实现USB口与UART口的数据互相传输

*提示：如果发送的数据属于“协议格式”中的指令，则会执行相应的指令而不会被转发透传*

设置运行界面显示元素
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

进行图像识别时，为了便于观察检测结果，需要对识别结果进行标识，Sentry2定义了3种标识元素：识别框、坐标、信息

.. image:: images/sentry2_set_display.png 

**识别框**:显示被测物体的轮廓范围，为一个矩形的方框，其大小为物体的宽和高，位置由物体的中心坐标来确定 

**坐标**:在图像中绘制出被测物体的水平和垂直坐标线，并显示其数值，X：水平位置，Y：垂直位置，W：物体宽度，H：物体高度

**信息**:显示物体的分类标签、名称内容等信息

*提示：当进行多结果检测时，绘制太多的元素可能会降低图像检测帧率，可适当关闭部分元素绘制功能* 

*提示：有些算法并不具备所有的绘制元素，比如“线条检测”不会绘制坐标线* 

*提示：当图像中没有显示任何检测结果时，可能是显示功能全部被关闭了，需要打开相关的功能即可* 

设置LED灯光颜色
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

进行图像识别时，可以通过传感器前面的LED灯光来指示检测结果，每检测一帧图像，会闪烁一次灯光，灯光颜色和亮度可以进行自定义设置

.. image:: images/sentry2_set_led.png 

用户可以分别设置“检测到”物体时的灯光颜色和“未检测到”时的灯光颜色，每按一次控件，将会改变一个颜色，切换顺序如下：

.. image:: images/sentry2_led_color_list.png 


其中，黑色代表关闭灯光

当“检测到”和“未检测到”颜色相同时，LED灯光将保持常亮，不再闪烁

亮度调节范围为0～15,其中0为关闭灯光，15为最亮，如果只作为一般性指示功能，亮度设为1或2即可

* 关闭灯光
    在某些情况下，灯光可能会对图像识别产生干扰（如颜色类算法，近距离物体识别时，等），此时需要关闭灯光，有两种方式可以关闭的灯光：
    
    1. 将“检测到”和“未检测到”设置为黑色
    
    2. 将亮度设置为0

* 补光灯功能
    当环境较暗时，或者处于逆光环境情况下，需要开启补光灯来照明，可以按照下面的方式设置：
    
    1. 将“检测到”和“未检测到”都设为白色，此时LED灯光将保持白色常亮状态，不再闪烁

    2. 将亮度提高，比如设为最大15,此时发光最亮

设置WiFi功能
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sentry2板载ESP8285-WiFi芯片，与K210主芯片之间通过UART实现数据通信，当开启“自定义算法”时，会启用ESP8285芯片，启用后功耗会有所增加

.. image:: images/sentry2_set_wifi.png 

**波特率**：支持“9600、74880、115200、921600、1152000、2000000、3000000、4000000”波特率，当控件位于最左侧时可以关闭wifi功能

**至UART**：开启或关闭WiFi芯片与UART端口的数据透传功能，开启后，可以实现WiFi芯片与UART口的数据互相传输，可以用于WiFi芯片与主控的数据通信

**至USB**：开启或关闭WiFi芯片与USB端口的数据透传功能，开启后，可以实现WiFi芯片与USB口的数据互相传输，可以用于WiFi芯片调试日志输出

*提示：如果发送的数据属于“协议格式”中的指令，则会执行相应的指令而不会被转发透传*

设置坐标系
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sentry2支持2种坐标系：绝对值坐标系、百分比坐标系

.. image:: images/sentry2_set_cord.png 

**绝对值坐标系**：返回图像中的实际坐标数据，与图像分辨率一致，水平方向范围“0～319”，垂直方向范围“0～239”，图像中心点坐标为（160,120），该模式具有更高的精确度。

**百分比坐标系**：将实际检测到的坐标结果量化至整幅图像“0～100”的范围区间内，返回其相对值坐标，水平X方向和垂直Y方向范围“0～100”，图像中心点坐标为（50,50）

设置系统语言
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sentry2支持2种系统语言：英语、简体中文。当系统语言发生变化时，可以通过该选项进行切换，设置后需要重启设备以完全生效

.. image:: images/sentry2_set_language.png 

*提示：选择简体中文时，并非所有文本都以汉字显示，例如所训练的人脸模型名称、深度学习训练的模型名称、二维码识别的字符等，暂时不支持中文显示*

设置寄存器
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

可以设置Sentry内部寄存器的一些操作：自动保存，保存当前值，恢复默认值

.. image:: images/sentry2_set_reg.png 

**自动保存**：开启后，当某些寄存器发生改变时会自动存储至Flash里，如算法参数、镜头参数等，关机后下次开机依然有效。关闭后，改变的值不会自动保存在Flash里，下次开机后自动复位，默认为关闭状态。

**保存当前值**：可以手动保存当前的所有寄存器的设置参数

**恢复默认值**：恢复寄存器为出厂状态。先点击此按键，再点击“确认”后才生效

摄像头设置
************************

数码变焦
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

当需要看清远处的物体时，可以对图像进行放大或缩小，支持1～5档调节

增大缩放值会让物体放大，但视野会变小，看到的东西会变少

减小缩放值会让物体缩小，但视野会变大，可以看到更多的东西

除了UI控件可以设置缩放值外，还支持导航快捷键来设置

向上长按：放大

向下长按：缩小

白平衡
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

在不同光照下（白光和黄光），白色会有一定的偏差，从而导致其他颜色的正常显示，此时需要设置白平衡来进行调节，一共有4种模式：自动、锁定、白光、黄光

自动：此为默认模式，适用于通用场景

锁定：当图像中存在大面积单色背景时，比如近距离识别颜色时，会导致图像发生偏色问题，将导致颜色识别出错，因此在识别之前需要进行白平衡的锁定，避免颜色自动调节，方法如下：
    
    1. 在相同的灯光环境下，将摄像头面向白纸，保持约20cm的距离；
    2. 进入“白平衡”设置页面，选择“锁定”模式；
    3. 点击“确认”，此时摄像头会记录下当前参数值，不再自动调整；
    4. 返回运行界面

白光：白色灯光环境下使用

黄光：黄色灯光环境下使用

饱和度
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

增大饱和度会让色彩变得鲜艳，色彩会被强化与突出，进行颜色检测和识别时，可以适当增大饱和度

减小饱和度会让色彩变得黯淡，很低时则类似于黑白画面

亮度
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

图像过暗时可以适当提高亮度，但如果在较亮的环境下提高，则图像会变得灰白，如蒙了一层雾气一般

当面对电脑屏幕等光源时，可以适当减小亮度

对比度
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

增大对比度会让相邻有色差的地方区分度更高，当进行黑白线条或二维码图案识别时，可以适当提高对比度

减小对比度会让图像看起来黯淡

锐化
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

增大锐化会让边缘轮廓更清晰，细节更明显，但过高会产生噪点

减小锐化图像会变得模糊

曝光
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

光线较强导致图像曝光时可以减小曝光值

反之如果环境较暗则可以增大曝光值

旋转镜头
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

开启后镜头画面将旋转180度


开启算法
************************

有多种方式可以开启/关闭算法：UI界面方式，导航键方式，指令方式

通过UI界面开启算法
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. image:: images/sentry2_run_vision_by_ui.png 

1. 进入“算法设置”页面，在左侧菜单栏选择要运行的算法，点击进入

2. 有些算法具有参数配置功能，可以点击“参数设置”控件进入详情页，对该算法进行参数调整，当导航悬停在某个控件上时，UI界面下方的滚动条会显示操作提示，设置结束后，点击“确认”或“对勾”返回

3. 如果右侧控件区域左下方显示”红色停止”按钮，则代表该算法目前为关闭状态，点击后变为“绿色运行“按钮，则代表开启算法，再次点击又会变为”红色停止“

**注意**：有些算法参数配置后下次启动算法时才生效

通过导航键开启算法
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. image:: images/sentry2_run_vision_by_stick.png 

1. 通过上下拨动导航键可以快速的切换算法，每次切换算法后，都会关闭之前的算法

2. 算法切换顺序按照算法ID排序

通过指令开启算法
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

该方式需要由主控设备读写寄存器来实现算法的开启或关闭，我们在多个编程平台提供了封装好的驱动库给用户使用

串口模式需要依照“标准协议指令”或“简单协议指令”来读写控制，详见相关章节介绍

I2C模式可直接读写寄存器

算法开启流程如下：
    
1. 向寄存器 0x20-VISION_ID 写入要开启的算法ID号
    
2. 向寄存器 0x21-VISIO_CONF1 中写入0x01,即可开启算法，写入0x00则关闭算法

详细设置，请查询寄存器列表

检测结果
************************

通过屏幕查看检测结果
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

当图像检测到目标物体后，会在屏幕中进行标识，各标识含义如下所示

.. image:: images/sentry2_vision_result.png 

通过指令读取检测结果
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

该方式需要由主控设备读写寄存器来读取结果，我们在多个编程平台提供了封装好的驱动库给用户使用

串口模式需要依照“标准协议指令”或“简单协议指令”来读写控制，详见相关章节介绍

I2C模式可直接读写寄存器

识别结果读取流程如下：
    
1. 向寄存器 0x20-VISION_ID 写入要读取的算法ID号
    
2. 读取寄存器 0x34-RESULT_NUM 的值来获取当前检测到了几个目标物体，例如，返回2,则表明检测到了2个物体

3. 向寄存器 0x24-RESULT_ID 写入待读取的结果编号，例如，写入1代表读取第1组结果，写入2代表读取第2个组果

4. 读取寄存器 0x80~0x89 的值来获取检测结果

    ========    ========================    ========================
    地址         名称                           含义
    ========    ========================    ========================
    0x80        RESULT_DATA1_H8             检测结果1,高8位
    0x81        RESULT_DATA1_L8             检测结果1,低8位
    0x82        RESULT_DATA2_H8             检测结果2,高8位
    0x83        RESULT_DATA2_L8             检测结果2,低8位
    0x84        RESULT_DATA3_H8             检测结果3,高8位
    0x85        RESULT_DATA3_L8             检测结果3,低8位
    0x86        RESULT_DATA4_H8             检测结果4,高8位
    0x87        RESULT_DATA4_L8             检测结果4,低8位
    0x88        RESULT_DATA5_H8             检测结果5,高8位
    0x89        RESULT_DATA5_L8             检测结果5,低8位
    ========    ========================    ========================

详细设置，请查询寄存器列表

.. _chapter_hardware_standard_protocol_index:

标准协议指令
----------------

在串口模式下，主控与Sentry2的数据交互需要通过协议来进行，标准协议指令具有规范的数据格式，结合寄存器表可以实现完整的数据交互功能和较高的通信效率。

指令格式
****************
START | LEN | ADDR | CMD | DATA | CHKSUM | END

========    ========    ================    ========
符号         含义         长度                描述
========    ========    ================    ========
START       帧头         1Byte               表示一个数据包的开始，始终为0xFF
LEN         长度         1Byte               数据包的总长度（字节），包含帧头和帧尾
ADDR        地址         1Byte               设备物理地址
CMD         指令         1Byte               指令代码，详见指令列表
DATA        数据         (LEN-6)Byte         数据内容，详见指令列表
CHKSUM      校验         1Byte               从帧头（含）到DATA数据的所有字节累加求和，进位丢弃
END         帧尾         1Byte               表示一个数据包的结束，始终为0xED
========    ========    ================    ========

数据交互方式
************************
串口模式下采用应答机制，传感器的数据交互完全由主控设备控制，传感器不会主动向主控发送数据。数据交互时，由主控设备先发送指令帧，然后传感器将会返回一个或多个应答帧，完成一次数据交互。


指令介绍
************************
================    ================    ================
指令代码              名称                描述
================    ================    ================
0x01                SetRegister         设置寄存器
0x02                GetRegister         读取寄存器
0x20                SetParam            设置算法参数
0x21                SetParamGroup       按组设置算法参数
0x22                GetResult           读取算法结果
0x23                GetResultGroup      按组读取算法结果
0x24                SetResult           设置算法结果
0x25                SetResultGroup      按组设置算法结果
================    ================    ================

* Param Group 参数组
    一组参数可以表示一个作用区域，每组参数最多可包含5个参数值，不同的算法对这5个参数值的含义可能是不同的。
    
    仅有部分算法具有参数设置功能，有的算法还可以设置多组参数，每组参数由Param ID进行标记。
    
    比如颜色识别算法，要设置25个检测区域，则需要写入25组参数

* Param Value 参数值
    每组参数可以由5个参数值来描述，不同算法的参数值的含义并不相同，详见下表

    ================    ========================    ========================    ========================    ========================    ========================
    算法                 Param Value1                Param Value2                Param Value3                Param Value4                Param Value5 
    ================    ========================    ========================    ========================    ========================    ========================
    颜色识别              检测区域中心点x坐标            检测区域中心点y坐标            检测区域宽度w                 检测区域高度h                 无
    色块检测              无                          无                           最小色块宽度w                 最小色块高度h                 待检测的颜色分类标签
    深度学习              无                          无                            无                          无                          0=删除该ID数据，100=训练该ID数据
    人脸识别              无                          无                            无                          无                          0=删除该ID数据，100=训练该ID数据
    ================    ========================    ========================    ========================    ========================    ========================
* Result Group 结果组
    一组数据表示一个检测结果，每组结果包含5个数据，但不同的算法对这5个数据的含义可能是不同的，部分算法可以返回多个结果，每组检测结果由ResultID进行标记。
* Result Data 结果数据
    ================    ========================    ========================    ========================    ========================    ========================    ========================
    算法                 Result Data1                Result Data1                Result Data3                Result Data4                Result Data5                备注
    ================    ========================    ========================    ========================    ========================    ========================    ========================
    颜色识别              R红色通道值                  G绿色通道值                   B蓝色通道值                      无                          颜色分类标签
    色块检测              中心x坐标                    中心y坐标                     宽度w                       高度h                        颜色分类标签
    线条检测              起点x坐标                    起点y坐标                     终点x坐标                    终点y坐标                     无
    标签识别              中心x坐标                    中心y坐标                     宽度w                       高度h                        分类标签
    深度学习              固定中心x坐标                 固定中心y坐标                 固定宽度w                    固定高度h                     分类标签                      分类标签需要先进行训练
    卡片识别              中心x坐标                    中心y坐标                     宽度w                       高度h                        分类标签
    人脸识别              中心x坐标                    中心y坐标                     宽度w                       高度h                        分类标签                      分类标签需要先进行训练
    20类物体识别           中心x坐标                    中心y坐标                     宽度w                       高度h                        分类标签
    二维码识别            中心x坐标                    中心y坐标                     宽度w                       高度h                         字符数量                      后续结果组为字符数据
    自定义算法            自定义含义                    自定义含义                    自定义含义                  自定义含义                      自定义含义
    移动物体检测           中心x坐标                    中心y坐标                     宽度w                       高度h                        无
    ================    ========================    ========================    ========================    ========================    ========================    ========================

* 0x01-SetRegister
    描述:设置寄存器，每次只可设置一个寄存器（一个字节）

    指令帧CMD：0x01

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    寄存器地址            待写入数据
    ================    ================    ================    ================    ================    ================    ================

    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    0x01                已写入数据
    ================    ================    ================    ================    ================    ================    ================

* 0x02-GetRegister
    描述:读取寄存器，每次只可读取一个寄存器（一个字节）

    指令帧CMD：0x02

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    寄存器地址            
    ================    ================    ================    ================    ================    ================    ================

    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    0x02                读取的数据
    ================    ================    ================    ================    ================    ================    ================

* 0x20-SetParam
    描述:设置指定算法同一类型的参数值，可以同时设置多个数据，比如单独设置颜色识别算法10个检测区域的x坐标

    指令帧-0x20

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Bytes    
    ================    ================    ================    ================    ================    ================    ================
    算法ID               参数类型             起始ParamID1         结束ParamIDn         参数1               参数2                参数n
    ================    ================    ================    ================    ================    ================    ================

    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    0x20                算法ID
    ================    ================    ================    ================    ================    ================    ================

* 0x21-SetParamGroup
    描述:设置指定算法的参数组数据，每个参数组包含5个数据项，比如同时设置颜色识别算法的5个检测区域x，y，w，h信息

    指令帧CMD：0x21

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Bytes               Bytes               Bytes
    ================    ================    ================    ================    ================    ================    ================
    算法ID               起始ParamID1         结束ParamIDn        参数组1              参数组2              参数组n
    ================    ================    ================    ================    ================    ================    ================

    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    0x21                算法ID
    ================    ================    ================    ================    ================    ================    ================

* 0x22-GetResult
    描述:获取指定算法算法的某一类型的检测结果，比如只获取颜色识别的标签数据，而不关心xy坐标

    指令帧CMD：0x22

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7    
    ================    ================    ================    ================    ================    ================    ================
    算法ID               数据类型             起始ResultID         结束ResultID         
    ================    ================    ================    ================    ================    ================    ================

    因为每个数据帧的最大长度只有255个字节，当检测结果帧数据长度超过此值时，将会产生多个数据帧，当CMD为0xEC时表示中间帧，为0xE0时表示结束帧
    
    应答帧CMD：0xEC或0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Bytes           
    ================    ================    ================    ================    ================    ================    ================
    0x22                图像帧号             算法ID              数据类型            起始ResultID1        结束ResultIDn        结果数据
    ================    ================    ================    ================    ================    ================    ================

* 0x23-GetResultGroup
    描述:获取指定算法每组的检测结果，一组检测结果包含5个数据项，比如同时获取颜色识别算法的5个区域的RGB值和分类标签值

    指令帧CMD：0x23

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7    
    ================    ================    ================    ================    ================    ================    ================
    算法ID               起始ResultID         结束ResultID         
    ================    ================    ================    ================    ================    ================    ================

    因为每个数据帧的最大长度只有255个字节，当检测结果帧数据长度超过此值时，将会产生多个数据帧，当CMD为0xEC时表示中间帧，为0xE0时表示结束帧
    
    应答帧CMD：0xEC或0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Bytes    
    ================    ================    ================    ================    ================    ================    ================
    0x23                图像帧号             算法ID               起始ResultID1        结束ResultIDn        结果组1              结果组n
    ================    ================    ================    ================    ================    ================    ================

* 0x24-SetResult
    描述:设置指定算法算法的某一类型的检测结果，用于将WiFi芯片中自定义算法的结果写入K210寄存器中，以便主控读取

    指令帧CMD：0x24

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7    
    ================    ================    ================    ================    ================    ================    ================
    算法ID               数据类型             起始ResultID         结束ResultID         
    ================    ================    ================    ================    ================    ================    ================

    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Byte7           
    ================    ================    ================    ================    ================    ================    ================
    0x24                算法ID               
    ================    ================    ================    ================    ================    ================    ================

* 0x25-SetResultGroup
    描述:设置指定算法每组的检测结果，一组检测结果包含5个数据项，用于将WiFi芯片中自定义算法的结果写入K210寄存器中，以便主控读取

    指令帧CMD：0x25

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Bytes               Bytes    
    ================    ================    ================    ================    ================    ================    ================
    算法ID               起始ResultID         结束ResultID         
    ================    ================    ================    ================    ================    ================    ================
    
    应答帧CMD：0xE0

    ================    ================    ================    ================    ================    ================    ================
    Byte1               Byte2               Byte3               Byte4               Byte5               Byte6               Bytes    
    ================    ================    ================    ================    ================    ================    ================
    0x25                算法ID  
    ================    ================    ================    ================    ================    ================    ================

.. _chapter_hardware_simple_protocol_index:

简单协议指令
----------------

该指令没有复杂的协议规范，只需要通过串口发送简单的字母和数字就可以开启算法和获取数据，无需开发驱动库，适用于任何有UART功能的主控平台，但也只适合简单的应用场景

指令格式
************************
CMD | ID | END

========    ================    ================    ========================
符号         含义                 长度                描述
========    ================    ================    ========================
CMD         指令字符              1                   指令字符，详见指令列表
ID          ID数字编号            1                   ID编号，可以为算法编号或结果编号
END         结束符                1                   可以为换行符，回车符，或者空格
========    ================    ================    ========================


指令列表
************************

================================    ========================    ================================================    =====================================================================================        ========================
操作                                    指令字符                       ID数字编号                                       返回                                                                                            举例
================================    ========================    ================================================    =====================================================================================        ========================
开启算法                               O 或 o                        算法编号                                          1：成功， 0：失败                                                                               O7开启人脸识别 
关闭算法                               C 或 c                        算法编号                                          1：成功， 0：失败                                                                               C7关闭人脸识别
查询检测结果数量                        N 或 n                        算法编号                                          检测到物体的数量，0为未检测到                                                                      N7返回人脸数量 
获取水平x坐标                           X 或 x                        检测结果的编号，可省略，默认为1                      物体的水平坐标值                                                                                 X1返回第1个人脸x坐标 
获取垂直y坐标                           Y 或 y                        检测结果的编号，可省略，默认为1                      物体的垂直坐标值                                                                                 Y3返回第3个人脸y坐标 
获取物体w宽度                           W 或 w                        检测结果的编号，可省略，默认为1                      物体的宽度值                                                                                     W返回第1个人脸宽度 
获取物体h高度                           H 或 h                        检测结果的编号，可省略，默认为1                      物体的高度值                                                                                     H返回第1个人脸高度 
获取物体分类标签                        L 或 l                         检测结果的编号，可省略，默认为1                     物体的分类标签                                                                                  L2返回第2个人脸的分类标签
获取所有结果                            A 或 a                        检测结果的编号，可省略，默认为1                     :ref:`返回结果说明<chapter_hardware_simple_protocol_a_index>`                                    A返回第1个人脸的所有结果
获取图片                               I 或 i                         无                                              :ref:`图片数据帧<chapter_hardware_image_protocol_index>`                                       I返回一张图片
================================    ========================    ================================================    =====================================================================================        ========================


.. _chapter_hardware_simple_protocol_a_index:

**指令A返回结果说明**

返回格式为：A+001+002+003+004+005

其中001为X坐标，002为Y坐标，003为W宽度，004为H高度，005为L标签

为方便解析，每个结果采用3位固定的数字组成，不足部分用0填充

**注意，对于线段检测和二维码等具有特殊返回结果的算法，返回结果的含义见各算法的介绍**


.. _chapter_hardware_image_protocol_index:

图像传输协议
----------------

Sentry2支持图像传输功能，可以将图片发送给WiFi芯片，UART端口或USB端口，支持RGB565，JPEG，JPEG-Base64格式。

指令格式
****************
START | TYPE | WIDTH | HEIGHT | LEN | DATA 

========    ================    ================    ========
符号         含义                 长度                描述
========    ================    ================    ========
START       帧头                 1Byte               表示一个数据包的开始，始终为0xF0
TYPE        图像格式              1Byte               2=RGB565,4=JPEG，5=JPEG-Base64
WIDTH       图像宽度              2Bytes              图像的宽度
HEIGHT      图像高度              2Bytes              图像的高度
LEN         数据长度              4Bytes              图像数据长度
DATA        图像数据              LEN                 图像数据
========    ================    ================    ========

**RGB565**：图像原始采样数据，采用2个字节表示一个像素点，数据较大，一副320×240的图片需要153600字节

**JPEG**：一种常见的图像压缩格式，可以将RGB565图片压缩至10～30KB，压缩率的大小取决于图片的颜色丰富度，颜色较少则压缩率高

**JPEG-Base64**：是将JPEG图片按照Base64规则进行编码，将十六进制HEX数据转为文本字符，便于网络传输和解析，通常用于云端图像识别

寄存器
----------------
请联系我们

技术：support@aitosee.com

销售：sales@aitosee.com





Sentry2MV 开发文档
==================

`Sentry2MV <https://github.com/AITosee/Sentry2MV>`_ 可直接在 Sentry2 上运行
`CanMV <https://developer.canaan-creative.com/canmv/main/canmv/index.html>`_
的一款固件，只要更新此款固件，即可在 Sentry2 上运行起 CanMV 上所有算法。

Sentry2MV 提供了更简易、更统一的算法调用接口，可以让初学者快速上手，使用 **MicroPython**
快速运行起各种算法。

开发环境搭建
++++++++++++

Sentry2MV 固件升级
------------------

TODO:

Sentry2MV 库下载到设备
----------------------

- 下载 Sentry2MV github 工程：https://codeload.github.com/AITosee/Sentry2MV/zip/refs/heads/main
- 解压下载上一步的下载的 `.zip` 文件
- 将 Sentry2 上的 SD 卡连接至电脑，并将解压得到的相关文件中的 `KPU/` 文件夹和 `sentry.py` 拷贝到 SD 卡上
- 弹出 SD 卡，并将 SD 卡插回 Sentry2

安装 CanMV IDE
---------------

软件下载
::::::::

- 官网下载：https://canaan-creative.com/developer

    .. image:: images/sentry2mv_canmv_ide_download.jpg

- github 下载：https://github.com/kendryte/canmv_ide/releases

    .. image:: images/sentry2mv_canmv_ide_download_from_github.jpg

软件安装
::::::::

- 下载后得到canmv-ide-windows-vx.x.x-gxxxxxx.exe文件，双击打开安装包，按照提示进行安装

    .. image:: images/sentry2mv_canmv_ide_install.jpg

功能界面介绍
::::::::::::

    .. image:: images/sentry2mv_canmv_ide_description.png

    区域①菜单栏：操作文件，使用工具等。

    区域②快捷按钮：区域①中的 **文件** 和 **编辑** 中部分功能的快捷方式。

    区域③连接设备：连接设备和程序控制按钮。

    区域④代码编辑区：编辑要运行的代码。

    区域⑤串行终端：显示串口打印的调试信息。

    区域⑥图像预览：显示摄像头的图像预览。

    区域⑦固件信息：显示连接的串口号以及固件的相关信息。

设备连接
::::::::

- 将 Sentry2 通过 TypeC 数据线连接到电脑USB口, 然后点击CanMV IDE左下角连接按钮

    .. image:: images/sentry2mv_canmv_ide_connection.png

- 弹出选择串口，选择 Sentry2 对应的串口号，如果有多个串口请先确定对应的串口号再点击OK打开

    .. image:: images/sentry2mv_canmv_ide_choose_port.png

- 连接成功会将图标变为已连接状态，同时灰色播放键变为绿色

    .. image:: images/sentry2mv_canmv_ide_connected.png

运行例程
::::::::

- `下载 <https://github.com/AITosee/Sentry2MV/tree/main/examples>`_ Sentry2MV 的相关例程。
- 点击绿色的播放键运行程序

    .. image:: images/sentry2mv_canmv_ide_download_example.png

- 绿色播放键图标变成红色停止键，点击一下可以停止运行的程序

    .. image:: images/sentry2mv_canmv_ide_stop_code.png

快速上手
++++++++

- Sentry2 I2C 初始化

.. code-block:: python
    :linenos:

    import sentry

    i2c = sentry.I2C(I2C.I2C0, freq=100000)
    devices = i2c.scan()
    print(devices)

- Sentry2 UART 初始化

.. code-block:: python
    :linenos:

    import sentry

    uart = sentry.UART(115200, 8, 1, 0, timeout=1000, read_buf_len=4096)

- Yolov2 通用检测

.. code-block:: python
    :linenos:

    import sentry
    import sensor, image, time, lcd
    import gc

    lcd.init()
    sensor.reset()  # Reset and initialize the sensor. It will
                    # run automatically, call sensor.run(0) to stop
    sensor.set_pixformat(sensor.RGB565)  # Set pixel format to RGB565 (or GRAYSCALE)
    sensor.set_framesize(sensor.QVGA)  # Set frame size to QVGA (320x240)
    sensor.skip_frames(time=1000)  # Wait for settings take effect.
    clock = time.clock()  # Create a clock object to track the FPS.

    # 填写类别名称，anchor，模型地址，类别等参数
    obj_name = ("face", )
    anchor = (0.893, 1.463, 0.245, 0.389, 1.55, 2.58, 0.375, 0.594, 3.099,
              5.038, 0.057, 0.090, 0.567, 0.904, 0.101, 0.160, 0.159, 0.255)
    model_path = "/sd/KPU/yolo_face_detect/yolo_face_detect.kmodel"
    classes = 1
    # 实例化 sentry2 Yolov2 检测器
    detector = sentry.Yolov2Detector()
    detector.init(model_path,
                  anchor,
                  img_w=320,
                  img_h=240,
                  net_w=320,
                  net_h=256,
                  classes=classes)

    while True:
        # 循环读图、处理图片，并打印结果
        clock.tick()  # Update the FPS clock.
        img = sensor.snapshot()
        dect = detector.process(img)
        fps = clock.fps()
        if len(dect) > 0:
            print("dect:", dect)
            for l in dect:
                img.draw_rectangle(l[0], l[1], l[2], l[3], color=(0, 255, 0))
                img.draw_string(l[0],
                                l[1] - 24,
                                obj_name[l[4]],
                                color=(0, 255, 0),
                                scale=2)

        a = img.draw_string(0,
                            0,
                            "%2.1ffps" % (fps),
                            color=(255, 255, 0),
                            scale=2.0)
        lcd.display(img)
        gc.collect()
    # 程序结束后释放检测器
    detector.deinit()

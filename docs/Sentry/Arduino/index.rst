Sentry4-Arduino 开发文档
========================

Sentry-Arduino 库是一个专门为 Arduino 系列开发板定制打造的驱动库，
用户可以使用该库迅速上手获取 Sentry 的识别结果，以及设置相关参数。

安装
----

1. `下载 <https://github.com/AITosee/Sentry-Arduino/releases>`_ Sentry ``.zip`` 库。
2. 打开 Arduino IDE ，点击 ``项目->加载库->添加.ZIP库``，选择上一步中下载的 ``.zip`` 文件，点击 ``确定`` 按钮完成库的添加。

    .. image:: images/arduine_add_library.png

快速上手
--------

Arduino 库中提供了丰富的例程，这些例程默认使用了 **串口模式**，以下内容均以串口模式作为通讯方式。

1. 接线

    默认使用串口模型，将 Sentry 对应的线接至 Arduino 除 ``Serial`` 外任意串口上。

    +---------+--------+
    | Arduino | Sentry |
    +=========+========+
    |   TX    |   RX   |
    +---------+--------+
    |   RX    |   TX   |
    +---------+--------+

    .. attention::
        Arduino Uno 只有一个硬件串口（用于传输打印信息至电脑端），建议使用软串口与 Sentry 进行通讯。

2. 设置 Sentry 的通讯模式

    - 将 Sentry 右上角摇杆向右拨动三次进入硬件配置界面，将 ``Output`` 设置为 ``UART``，点击 ``YES`` 并向左拨动三次摇杆退出设置。

        .. image:: images/sentry_set_uart_mode.jpg

3. 烧录例程

    打开 Arduino IDE，依次点击 ``File->Examples->Sentry``，选择任意例程，点击 ``Upload`` 上传程序至 Arduino 主控。

4. 观察现象

    程序烧录完毕后，打开 Arduino IDE 中的 ``Serial Monitor``，识别到算法对应的物体后即会有相应的结果输出。

使用
----

1. 初始化

    Sentry-Arduino 库支持 UART/I2C 两种通讯方式，用户可以通过以下方式初始化 Sentry。

    - UART:

        .. code-block:: cpp
            :linenos:
            :emphasize-lines: 10,11

            #include <Arduino.h>
            #include <Sentry.h>

            /* 实例化 Sentry，创建 Sentry 变量 */
            Sentry sentry;

            void setup() {
                /* 设置 Arduino(mega2560) 串口3波特率与 Sentry 一致 */
                Serial3.begin(9600);
                /* 使用串口初始化 Sentry，若 err 返回为 0，则初始化正常，否则返回对应错误码。 */
                sentry_err_t err = sentry.begin(&Serial3);
            }

        .. attention::

            Arduino 部分型号（如：UNO）至含有一个硬件串口，该类主控上建议使用 `软串口 <https://www.arduino.cc/en/Reference/SoftwareSerialConstructor>`_。


    - I2C

        .. code-block:: cpp
            :linenos:
            :emphasize-lines: 10,11

            #include <Arduino.h>
            #include <Sentry.h>
            #include <Wire.h>

            /* 实例化 Sentry，创建 Sentry 变量 */
            Sentry sentry;

            void setup() {
                Wire.begin();
                /* 使用 I2C 初始化 Sentry，若 err 返回为 0，则初始化正常，否则返回对应错误码。 */
                sentry_err_t err = sentry.begin(&Wire);
            }

    .. note::

        若初始化返回错误码为 ``0xXX``，则表示库过旧，部分功能可能不支持，请更新至最新版本库；
        若返回其他类型错误，则表示通讯异常，请检查 Sentry 接线与模式是否与代码中的一致。

    .. warning::

        同时开启过多算法会导致算法执行速度变慢，响应时间变长，部分内存较小的主控会出现内存不足而导致初始化失败的情况。


2. 开启算法

    .. code-block:: cpp
        :linenos:

        /* 开启卡片检测算法 */
        err = sentry.VisionBegin(kVisionCard);

    .. note::

        当前支持的算法包括：

        ============    ===========
        颜色识别        kVisionColorRecog
        色块检测        kVisionColorDetect
        线条检测        kVisionLine
        卡片检测        kVisionCard
        人脸检测        kVisionFace
        20类物体检测    kVision20Classes
        二维码识别      kVisionQrCode
        ============    ===========

3. 获取算法识别结果

    .. code-block:: cpp
        :linenos:

        void loop() {
            unsigned long ts = millis();
            /* 获取算法识别到目标的数量 */
            int obj_num = sentry.GetValue(kVisionCard, kStatus);
            unsigned long te = millis();
            if (obj_num) {
                printf("Totally %d objects in %lums:\n", obj_num, te - ts);
                /* 打印算法所有识别到物体的位置和标签 */
                for (int i = 0; i < obj_num; ++i) {
                    int x = sentry.GetValue(kVisionCard, kXValue, i);
                    int y = sentry.GetValue(kVisionCard, kYValue, i);
                    int w = sentry.GetValue(kVisionCard, kWidthValue, i);
                    int h = sentry.GetValue(kVisionCard, kHeightValue, i);
                    int l = sentry.GetValue(kVisionCard, kLabel, i);
                    printf("  obj[%d]: x=%d,y=%d,w=%d,h=%d, label=%s\n", i, x, y, w, h, l);
                }
            }
        }

    .. tip::

        通过重定向标准输出流到对应的串口，可以在 Arduino 上使用 ``printf`` 向对应串口打印输出字符。（该方法当前不支持浮点数打印输出）

        .. code-block:: cpp
            :linenos:

            /* 将标准输出流重定向至串口 */
            int serial_putc(char c, struct __file*) {
                Serial.write(c);
                return c;
            }

            void setup() {
                /* 在初始化函数中初始化串口和标准输出流 */
                Serial.begin(9600);
                fdevopen(&serial_putc, 0);
            }


API 说明
--------

Coming soon...

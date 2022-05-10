.. _chapter_mindplus_index:

Sentry-Mind+ 开发文档
=====================

`ext-sentry <https://github.com/AITosee/ext-sentry>`_ 为适配 `Mind+ <http://mindplus.cc/>`_ 开发的驱动库，
适用于 ``掌控版/microbit`` 在 Mind+ 上的 ``图形化`` 及 ``microPython`` 两大编程语言的开发。

安装
----

1. 下载对应平台的 `Mind+软件 <http://mindplus.cc/download.html>`_。
2. 打开 Mind+，新建项目后选择 ``上传模式``。
3. 点击右下角齿轮图标，并点击 ``用户库``。
4. 在搜索栏输入 ``https://github.com/AITosee/ext-sentry``，并点击添加。

例程
----

1. 20类卡片识别

    .. image:: images/mindplus_sentry_example_20class.png

2. 颜色识别

    .. image:: images/mindplus_sentry_example_color.png

3. 二维码检测

    .. image:: images/mindplus_sentry_example_qrcode.png

4. 色块检测

    .. image:: images/mindplus_sentry_example_blob.png

模块说明
--------

1. 初始化模块

    选择一个端口初始化 Sentry，该方法必须在使用其他 Sentry 相关模块之前调用。

    .. image:: images/mindplus_sentry_init.png

2. 开启/关闭算法

    开启或关闭某个算法。

    .. image:: images/mindplus_sentry_set_vision_status.png

3. 设置返回结果坐标格式

    可选择返回坐标为 ``绝对坐标（0~长/宽）`` 或 ``相对坐标（0~100）``。

    .. image:: images/mindplus_sentry_set_coordinate_type.png

4. 获取算法检测结果的数量

    .. image:: images/mindplus_sentry_get_result_num.png

5. 获取算法检测结果

    获取算法检测结果的具体数值，多个结果可通过设置第三个参数 ``第N个结果`` 来获取不同结果的值。

    .. image:: images/mindplus_sentry_get_value.png

6. 获取二维码算法识别结果

    返回二维码识别字符串。

    .. image:: images/mindplus_sentry_get_qrcode_value.png

7. 判断算法结果标签

    判断算法第N个结果是否为某标签，返回 ``是`` 或 ``否``。

    .. image:: images/mindplus_sentry_is_label.png

8. 获取颜色识别算法识别结果

    获取识别到颜色的 RGB 值。

    .. image:: images/mindplus_sentry_get_color.png

9. 设置摄像头白平衡

    某些特殊场景下可固定摄像头白平衡。

    .. image:: images/mindplus_sentry_set_camera_awb.png

10. 设置颜色识别算法参数

        设置颜色识别算法需要识别的位置及大小。

        .. image:: images/mindplus_sentry_set_color_param.png

11. 设置色块检测算法参数

        设置色块检测算法的最小识别大小。

        .. image:: images/mindplus_sentry_set_blob_param.png

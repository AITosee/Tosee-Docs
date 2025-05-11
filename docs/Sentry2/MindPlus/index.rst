.. _chapter_mindplus_index:

Sentry2-Mind+ 开发文档
=======================

`Sentry2-MindPlus <https://github.com/AITosee/Sentry2-MindPlus>`_ 为适配 `Mind+ <http://mindplus.cc/>`_ 开发的驱动库，
支持 micro:bit、Arduino 系列与掌控板基于C语言的图形化代码编程以及掌控板基于microPython语言的图形化代码编程。

安装
----

1. 下载对应平台的 `Mind+软件 <http://mindplus.cc/download.html>`_
2. 打开Mind+，新建项目后选择 ``上传模式``
3. 点击左下角的扩展按钮，选择需要使用的主控板，然后点击 ``用户库``
4. 在搜索栏输入 ``https://github.com/AITosee/Sentry2-MindPlus``，并点击添加

.. note::
    如需旧版V1.1.5库，可以下载（超链接 https://github.com/AlTosee/Sentry2-MindPlus/archive/refs/tags/v1.1.5.zip ）
    后通过 ``导入用户库`` 继续使用

例程
----

请从 `网盘 <https://pan.baidu.com/s/1Ur39pkhnL8yznRqGbX2tkA?pwd=1022>`_ 下载例程

路径：资料下载->视觉传感器->Sentry2->出厂固件->应用例程

模块说明
--------

1. 初始化模块

    选择一个端口初始化 Sentry，该方法必须在使用其他 Sentry 相关模块之前调用。

    .. image:: images/mindplus_sentry_init.png

2. 开启/关闭算法

    开启或关闭某个算法。

    .. image:: images/mindplus_sentry_set_vision_status.png

3. 设置摄像头白平衡

    某些特殊场景下可固定摄像头白平衡。

    .. image:: images/mindplus_sentry_set_camera_awb.png

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

9. 获取线条检测算法的结果

    .. image:: images/mindplus_sentry_get_line.png

10. 设置颜色识别算法参数

        设置颜色识别算法需要识别的位置及大小。

        .. image:: images/mindplus_sentry_set_color_param.png

11. 设置色块检测算法参数

        设置色块检测算法的最小识别大小。

        .. image:: images/mindplus_sentry_set_blob_param.png

12. 设置通用算法的参数

        .. image:: images/mindplus_sentry_set_param.png

13. 设置算法参数的组数

        .. image:: images/mindplus_sentry_set_param_num.png

.. _chapter_makecode_index:

Sentry-MakeCode 开发文档
========================

`pxt-sentry <https://github.com/AITosee/pxt-sentry>`_ 为适配 ``microbit&MakeCode`` 开发的驱动库，
适用于 ``microbit`` 在 `MakeCode <https://makecode.microbit.org/>`_ 上的 ``图形化`` 开发。

安装
----

1. 打开 `MakeCode 在线编程界面 <https://makecode.microbit.org/>`_。
2. 新建工程。
3. 依次点击 ``高级→扩展``，在搜索栏输入 ``https://github.com/AITosee/pxt-sentry``。
4. 点击搜索出来的库添加，即可完成库的加载。

例程
----

详见： `使用方法 <https://github.com/AITosee/pxt-sentry#%E4%BD%BF%E7%94%A8%E6%96%B9%E6%B3%95>`_

模块简介
--------

1. 初始化模块

    选择一个端口初始化 Sentry，该方法必须在使用其他 Sentry 相关模块之前调用。

    .. image:: images/makecode_sentry_init.png

2. 开启/关闭算法

    开启或关闭某个算法。

    .. image:: images/makecode_sentry_set_vision_status.png

3. 设置返回结果坐标格式

    可选择返回坐标为 ``绝对坐标（0~长/宽）`` 或 ``相对坐标（0~100）``。

    .. image:: images/makecode_sentry_set_coordinate_type.png

4. 获取算法检测结果的数量

    .. image:: images/makecode_sentry_get_result_num.png

5. 获取算法检测结果

    获取算法检测结果的具体数值，多个结果可通过设置第三个参数 ``索引N`` 来获取不同结果的值。

    .. image:: images/makecode_sentry_get_value.png

6. 获取二维码算法识别结果

    返回二维码识别字符串。

    .. image:: images/makecode_sentry_get_qrcode_value.png

7. 判断算法结果标签

    判断算法第N个结果是否为某标签，返回 ``是`` 或 ``否``。

    .. image:: images/makecode_sentry_is_label.png

8. 获取颜色识别算法识别结果

    获取识别到颜色的 RGB 值。

    .. image:: images/makecode_sentry_get_color.png

9. 设置摄像头白平衡

    某些特殊场景下可固定摄像头白平衡。

    .. image:: images/makecode_sentry_set_camera_awb.png

10. 设置颜色识别算法参数

        设置颜色识别算法需要识别的位置及大小。

        .. image:: images/makecode_sentry_set_color_param.png

11. 设置色块检测算法参数

        设置色块检测算法的最小识别大小。

        .. image:: images/makecode_sentry_set_blob_param.png

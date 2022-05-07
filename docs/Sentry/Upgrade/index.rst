固件升级教程
===================

准备工作
--------

1. 通过百度网盘下载对应 ``固件`` 及 ``固件更新工具``： https://pan.baidu.com/s/1HlYivYUUBt0ubTfRAchfMQ?pwd=ijxp (密码: ijxp)
2. 解压 ``固件更新工具`` 压缩包备用

固件升级步骤
------------

1. 安装USB驱动
    安装USB驱动工具，如果电脑可以识别设备，则可以不用安装 :download:`点击下载驱动文件 <http://www.wch.cn/downloads/file/315.html?time=2022-05-07%2016:08:41&code=9Nh29r7jiQsj7QDu5IffgdrpzpKC0igITm3n3zuj>`

2. 连接设备

    将视觉传感器通过 Type-C USB 数据线连接至电脑

3. 配置信息

    打开 ``kflash_gui/`` 文件夹里的 ``kflash_gui.exe`` 应用程序，按照下图所示步骤进行操作。

    .. image:: images/sentry_upgrade_kflash_gui.png

4. 下载固件

    点击“下载”后将会出现下图所示界面，此时 **垂直压按视觉传感器的摇杆键约 2 秒** 来启动下载并等待下载完成.

    .. image:: images/sentry_upgrade_press_key.png
        :scale: 50 %

    .. image:: images/sentry_upgrade_kflash_download.png

5. 等待下载完成

    .. image:: images/sentry_upgrade_download_success.png

6. 重启传感器

    固件更新完成后传感器会自动重启,如果没有,可以短按 ``复位键`` 或者重新上电来重启设备。

# 坐标

QMouseEvent中的坐标
QMouseEvent中保存了两个坐标，一个是全局坐标即**相对屏幕左上角**的坐标，也叫屏幕坐标，当然另外一个是局部坐标，局部坐标是相对当前活动有焦点的窗口的左上角的坐标。

名称|作用
---|---
全局坐标(globalPos())|桌面屏幕坐标(screen coordinates)，这个跟windows下的调用getCursorPos函数得到的结果一致。
局部坐标(pos())|相对当前active widget的坐标，左上角坐标为（0， 0）。

## MouseEvent

>Mouse events occur when a mouse button is pressed or released inside a widget, or when the mouse cursor is moved.  
>Mouse move events will occur only when a mouse button is pressed down, unless mouse tracking has been enabled with `QWidget::setMouseTracking()`.  
>Qt automatically grabs the mouse when a mouse button is pressed inside a widget; the widget will continue to receive mouse events until the last mouse button is released.  
>A mouse event contains a special accept flag that indicates whether the receiver wants the event. You should call `ignore()` if the mouse event is not handled by your widget. A mouse event is propagated up the parent widget chain until a widget accepts it with accept(), or an event filter consumes it.  
>Note: If a mouse event is propagated to a widget for which Qt::WA_NoMousePropagation has been set, that mouse event will not be propagated further up the parent widget chain.  
>The state of the keyboard modifier keys can be found by calling the `modifiers()` function, inherited from QInputEvent.  
>The functions pos(), x(), and y() give the cursor position relative to the widget that receives the mouse event. If you move the widget as a result of the mouse event, use the global position returned by globalPos() to avoid a shaking motion.  
>The QWidget::setEnabled() function can be used to enable or disable mouse and keyboard events for a widget.  
>Reimplement the QWidget event handlers, `QWidget::mousePressEvent()`, `QWidget::mouseReleaseEvent()`, `QWidget::mouseDoubleClickEvent()`, and `QWidget::mouseMoveEvent()` to receive mouse events in your own widgets.  
>See also `QWidget::setMouseTracking()`, `QWidget::grabMouse()`, and `QCursor::pos()`.  

当在小部件内按下或释放鼠标按钮或移动鼠标光标时，会发生鼠标事件。  
除非通过QWidget :: setMouseTracking（）启用了鼠标跟踪，否则只有在按下鼠标按钮时才会发生鼠标移动事件。  
当在小部件内按下鼠标按钮时，Qt会自动抓住鼠标。 小部件将继续接收鼠标事件，直到释放最后一个鼠标按钮。  
鼠标事件包含一个特殊的接受标志，该标志指示接收者是否想要该事件。 如果您的窗口小部件未处理鼠标事件，则应调用ignore（）。 鼠标事件将在父窗口小部件链上传播，直到窗口小部件使用accept（）接受它，或者事件过滤器将其消耗掉为止。  
注意：如果将鼠标事件传播到已设置了Qt :: WA_NoMousePropagation的窗口小部件，则该鼠标事件将不会在父窗口小部件链中进一步传播。  
可以通过调用从QInputEvent继承的Modifys（）函数来找到键盘修饰键的状态。  
函数pos（），x（）和y（）提供相对于接收鼠标事件的小部件的光标位置。 如果由于鼠标事件而移动了窗口小部件，请使用globalPos（）返回的全局位置以避免晃动。  
QWidget :: setEnabled（）函数可用于启用或禁用小部件的鼠标和键盘事件。  
重新实现QWidget事件处理程序，QWidget :: mousePressEvent（），QWidget :: mouseReleaseEvent（），QWidget :: mouseDoubleClickEvent（）和QWidget :: mouseMoveEvent（），以在您自己的窗口小部件中接收鼠标事件。  
另请参见QWidget :: setMouseTracking（），QWidget :: grabMouse（）和QCursor :: pos（）。
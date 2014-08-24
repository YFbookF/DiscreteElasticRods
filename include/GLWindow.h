#ifndef __GL_WINDOW_H__
#define __GL_WINDOW_H__


#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/VertexArrayObject.h>
#include <ngl/Obj.h>

#include "Scene.h"
#include "TransformTool.h"

// must be included after our stuff becuase GLEW needs to be first
#include <QtOpenGL>

//----------------------------------------------------------------------------------------------------------------------
/// @file GLWindow.h
/// @brief a basic Qt GL window class for ngl demos
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/10/10
/// Revision History :
/// Initial Version 10/10/10 (Binary day ;-0 )
/// @class GLWindow
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------
class GLWindow : public QGLWidget
{

// must include this if you use Qt signals/slots
Q_OBJECT

public :
//----------------------------------------------------------------------------------------------------------------------
/// @brief Constructor for GLWindow
/// @param[in] _timer the time value for simulation updates
/// @param [in] _parent the parent window to create the GL context in
//----------------------------------------------------------------------------------------------------------------------
	GLWindow(const QGLFormat _format, int _timer,QWidget *_parent );
//----------------------------------------------------------------------------------------------------------------------
/// @brief dtor
//----------------------------------------------------------------------------------------------------------------------
	~GLWindow();
//----------------------------------------------------------------------------------------------------------------------
/// @brief set the scene to render
/// @param[in] scene - the scene
//----------------------------------------------------------------------------------------------------------------------
    inline void setScene(Scene *scene) { m_scene = scene; }

    void setSelectedObject(RenderObject *object);
//----------------------------------------------------------------------------------------------------------------------
/// @brief start the simulation timer
//----------------------------------------------------------------------------------------------------------------------
	void startSimTimer();
//----------------------------------------------------------------------------------------------------------------------
/// @brief stop the simulation timer
//----------------------------------------------------------------------------------------------------------------------
	void stopSimTimer();

public slots :
//----------------------------------------------------------------------------------------------------------------------
/// @brief set the timer duration value
/// @param[in] _v the timer value in ms
//----------------------------------------------------------------------------------------------------------------------
    inline void setTimerDuration(int v){ m_timerValue = v;}

private :
//----------------------------------------------------------------------------------------------------------------------
/// @brief scene to render
//----------------------------------------------------------------------------------------------------------------------
    Scene *m_scene;
//----------------------------------------------------------------------------------------------------------------------
/// @brief Our Camera
//----------------------------------------------------------------------------------------------------------------------
    ngl::Camera *m_cam;
//----------------------------------------------------------------------------------------------------------------------
/// @brief array of VAO objects created for each mesh in scene, used for fast rendering
//----------------------------------------------------------------------------------------------------------------------
    std::vector<ngl::VertexArrayObject*> m_VAOList;
    ngl::VertexArrayObject* m_strandVAO;
//----------------------------------------------------------------------------------------------------------------------
/// @brief selected object to which transformations calculated on mouse movement are applied
/// if NULL camera is modified
//----------------------------------------------------------------------------------------------------------------------
    RenderObject* m_selectedObject;
    TransformTool m_selectedTransform;
    TransformTool m_cameraTransform;

//----------------------------------------------------------------------------------------------------------------------
/// @brief transformation stack for the gl transformations etc
//----------------------------------------------------------------------------------------------------------------------
/// @brief our transformation stack used for drawing
//----------------------------------------------------------------------------------------------------------------------
    Transformation m_transform;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the timer
//----------------------------------------------------------------------------------------------------------------------
    int m_timer;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the timer value in ms
//----------------------------------------------------------------------------------------------------------------------
    int m_timerValue;
//----------------------------------------------------------------------------------------------------------------------
/// @brief flag to indicate if the mouse button is pressed when dragging
//----------------------------------------------------------------------------------------------------------------------
    bool m_rotate;
//----------------------------------------------------------------------------------------------------------------------
/// @brief flag to indicate if the mouse button is pressed when dragging
//----------------------------------------------------------------------------------------------------------------------
    bool m_zoom;
    bool m_pan;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the previous x mouse value
//----------------------------------------------------------------------------------------------------------------------
    int m_mouseX;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the previous y mouse value
//----------------------------------------------------------------------------------------------------------------------
    int m_mouseY;

protected:
//----------------------------------------------------------------------------------------------------------------------
/// @brief  The following methods must be implimented in the sub class
/// this is called when the window is created
//----------------------------------------------------------------------------------------------------------------------
    void initializeGL();
//----------------------------------------------------------------------------------------------------------------------
/// @brief this is called whenever the window is re-sized
/// @param[in] _w the width of the resized window
/// @param[in] _h the height of the resized window
//----------------------------------------------------------------------------------------------------------------------
    void resizeGL(const int _w, const int _h);
//----------------------------------------------------------------------------------------------------------------------
/// @brief this is the main gl drawing routine which is called whenever the window needs to
/// be re-drawn
//----------------------------------------------------------------------------------------------------------------------
    void paintGL();

private :
//----------------------------------------------------------------------------------------------------------------------
/// @brief this method is called every time a mouse is moved
/// @param _event the Qt Event structure
//----------------------------------------------------------------------------------------------------------------------
	void mouseMoveEvent ( QMouseEvent * _event );
//----------------------------------------------------------------------------------------------------------------------
/// @brief this method is called everytime the mouse button is pressed
/// inherited from QObject and overridden here.
/// @param _event the Qt Event structure
//----------------------------------------------------------------------------------------------------------------------
	void mousePressEvent ( QMouseEvent *_event );

//----------------------------------------------------------------------------------------------------------------------
/// @brief this method is called everytime the mouse button is released
/// inherited from QObject and overridden here.
/// @param _event the Qt Event structure
//----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent (QMouseEvent *_event );

//----------------------------------------------------------------------------------------------------------------------
/// @brief timer event trigered by startTimer
//----------------------------------------------------------------------------------------------------------------------
	void timerEvent(QTimerEvent *_event	);

// ============= various draw related utility functions ===============
    void loadMatricesToShader();
    void loadMatricesToHairShader();
    void loadMatricesToHairShader2();

    void buildVAOs(const std::vector<Mesh*>& meshList, std::vector<ngl::VertexArrayObject*>& o_VAOList) const;
    void feedVAO(const Mesh& mesh, ngl::VertexArrayObject& o_vao) const;
    void drawHairStrand(const ElasticRod& strand);
};

#endif

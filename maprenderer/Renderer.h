
#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickWindow>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Coordinate.h"
#include "Polygon.h"

namespace Map
{
    class Renderer : public QObject, protected QOpenGLFunctions
    {
        Q_OBJECT
    public:

        ~Renderer();

        void setVertices(const std::vector<std::vector<Coordinate>> &vertices);
        void setPolygons(const std::vector<Polygon> &polygons);
        void setViewportSize(const QSize &size);
        void setWindow(QQuickWindow *window);

        void panLeft();
        void panRight();
        void panUp();
        void panDown();


        void pan(const glm::vec2 &direction);
        void zoomIn(int x, int y);
        void zoomOut(int x, int y);

    public slots:
        void init();
        void paint();

    protected:
        QSize m_viewportSize;
        qreal m_t = 0.0;
        QOpenGLShaderProgram *m_program = nullptr;
        QQuickWindow *m_window = nullptr;
        std::vector<std::vector<Coordinate>> m_vertices;
        std::vector<Polygon> m_polygons;
        float m_zoomFactor = 1.0f;
        glm::mat4 m_modelMatrix = glm::mat4(1.0f);
        float m_centerX;
        float m_centerY;
    };
}

#endif // MAP_RENDERER_H
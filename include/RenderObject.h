#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Mesh.h"
#include "AABB.h"
#include "CollisionEllipsoid.h"


class RenderObject
{
public:
    RenderObject(const Mesh* _mesh, const mg::Matrix4D& _transform , int _shaderId = -1);
    ~RenderObject() {}

    unsigned getMeshId() const;
    const Mesh* getMesh() const;
    void setMesh(const Mesh* _mesh);

    const mg::Matrix4D& getTransform() const { return m_transform; }
    void setTransform(const mg::Matrix4D& t);
    mg::Vec3D getPosition() const  { return mg::matrix_get_translation(m_transform); }

    mg::Real getBoundingRadius() const { return m_boundingRadius; }
    mg::Real getMeshBoundingRadius() const { return m_meshBoundingRadius; }
    const AABB& getMeshAABB() const { return m_meshAABB; }

    void addCollisionShape(const CollisionEllipsoid& ellipsoid);
    bool isInsideObject(const mg::Vec3D& p, mg::Vec3D& o_collisionPoint, mg::Vec3D& o_normal) const;

protected:
    void calcBoundaries();

    const Mesh* m_mesh;
    mg::Matrix4D m_transform;

    AABB m_meshAABB;
    mg::Real m_meshBoundingRadius;
    mg::Real m_boundingRadius;

    std::vector<CollisionEllipsoid> m_collisionShapes;

    int m_shaderId;
};

#endif // GEOMETRY_H

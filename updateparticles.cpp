#include "updateparticles.h"

UpdateParticles::UpdateParticles()
{
    //particleArray.push_back(new Particle());
}

UpdateParticles::~UpdateParticles()
{
}

void UpdateParticles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int p_i = 0; p_i < particleArray.length(); ++p_i){
        for(int p_j = p_i; p_j < particleArray.length(); ++p_j){
            if(p_i != p_j){
                double force = gravity(*particleArray[p_i], *particleArray[p_j]);
                //qDebug() << "Force scalar: " << p_i << " " << p_j << force;

                //force = force > 2 ? 2 : force;

                Vector2D pos_ij = (particleArray[p_i]->position).getPositionVector(particleArray[p_j]->position);
                pos_ij.normalise();
                pos_ij *= (force / particleArray[p_i]->mass);

                //qDebug() << pos_ij.getX() << "," << pos_ij.getY();
                particleArray[p_i]->force += pos_ij;
                particleArray[p_i]->velocity_inst += particleArray[p_i]->force;

                Vector2D pos_ji = (particleArray[p_j]->position).getPositionVector(particleArray[p_i]->position);
                pos_ji.normalise();
                pos_ji *= (force / particleArray[p_j]->mass);

                //qDebug() << pos_ji.getX() << "," << pos_ji.getY();

                particleArray[p_j]->force += pos_ji;
                particleArray[p_j]->velocity_inst += particleArray[p_j]->force;

            }
        }
    }

    for(it = particleArray.begin(); it != particleArray.end(); ++it){
        (*it)->paint(painter);
    }

    /*for(int p_i = 0; p_i < particleArray.length(); ++p_i){
        if(particleArray[p_i]->position.getX() > (sceneWidth / 2) || particleArray[p_i]->position.getX() < -(sceneWidht / 2)){
            particleArray[p_i]->velocity.setX(-particleArray[p_i]->velocity.getX());
        }

        if(particleArray[p_i]->position.getY() > (sceneHeight / 2) || particleArray[p_i]->position.getY() < - (sceneHeight / 2)){
            particleArray[p_i]->velocity.setY(-particleArray[p_i]->velocity.getY());
        }
    }*/
}

QRectF UpdateParticles::boundingRect(void) const
{
    return QRectF(0,0,0,0);
}

float UpdateParticles::gravity(Particle& p1, Particle& p2)
{
    double d = p1.position.distance(p2.position);
    return (G * (p1.mass) * (p2.mass)) / (d * d);
}

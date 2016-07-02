/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package velocity;

import main_src.Particle;

/**
 *
 * @author Geraldo e Iago
 */
public class VelocityNormal extends AbstractVelocity{

    @Override
    public void calculate(Particle particle, int pos,
            double maxVel, int loopCount, int maxLoop)
    {
        double c1 = 2.05;
        double c2 = 2.05;
        
        double rand1 = this.getRandom();
        double rand2 = this.getRandom();
        
        double velocity = particle.getVelocity(pos);
        velocity += c1 * rand1 * (particle.getPBest(pos) - particle.getData(pos));
        velocity += c2 * rand2 * (particle.getGBest(pos) - particle.getData(pos));
        
        //clamping
        if(velocity > maxVel)
            velocity = maxVel;
        if(velocity < -maxVel)
            velocity = -maxVel;
        
        particle.setVelocity(pos, velocity);
    }
}

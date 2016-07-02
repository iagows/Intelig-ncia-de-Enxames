/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package velocity;

import main_src.Particle;

/**
 *
 * @author iago
 */
public class VelocityClerc extends AbstractVelocity{

    private double c1;
    private double c2;
    private double X;
    private double phi;
    
    public VelocityClerc()
    {
        super();
        this.c1 = this.getRandom(1,4);
        c2 = 4.1 - c1;
        this.phi = getPhi();
        this.X = getX();
    }
    @Override
    public void calculate(Particle particle, int currentDimension, double maxVel, int loopCount, int maxLoop)
    {
        double rand1 = this.getRandom();
        double rand2 = this.getRandom();
        
        double velocity = X*(particle.getVelocity(currentDimension) +
                                 (c1 * rand1 * (particle.getPBest(currentDimension) - particle.getData(currentDimension))) +
                                 (c2 * rand2 * (particle.getGBest(currentDimension) - particle.getData(currentDimension))));

        particle.setVelocity(currentDimension, velocity);
    }
    
    private double getX()
    {
        double root = Math.sqrt((phi*phi)-(4*phi));
        double bot = 2 - phi - root;
        if(bot < 0) bot = -bot;
        return 2/bot;
    }
    
    private double getPhi()
    {
        return c1+c2;
    }
    
}

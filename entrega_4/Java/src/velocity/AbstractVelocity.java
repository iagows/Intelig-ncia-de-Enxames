/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package velocity;

import java.util.concurrent.ThreadLocalRandom;
import main_src.Particle;

/**
 *
 * @author iago
 */
public abstract class AbstractVelocity implements IVelocity{
    
    @Override
    abstract public void calculate(Particle particle, int currentDimension, double maxVel, int loopCount, int maxLoop);

    /**
     * 
     * @return Um double entre 0 e 1
     */
    @Override
    public double getRandom() {
        return Math.random();
    }
    
    @Override
    public double getRandom(double min, double max)
    {
        return ThreadLocalRandom.current().nextDouble((int)min, (int)max);
    }
}

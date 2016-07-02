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
public interface IVelocity
{
    public void calculate(Particle particle, int currentDimension,
            double maxVel, int loopCount, int maxLoop);
    public double getRandom();
    public double getRandom(double min, double max);
}

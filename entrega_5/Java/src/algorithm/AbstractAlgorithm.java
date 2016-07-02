/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithm;

import main_src.Particle;
import java.util.ArrayList;

/**
 *
 * @author Geraldo e Iago
 */
public abstract class AbstractAlgorithm implements IAlgorithm
{
    abstract public void init();
    abstract public double fitness(Particle part, ArrayList<Particle> others);
    
    abstract public double getInitialBest();
    
    public double getMin()
    {
        return this.min;
    }
    
    public double getMax()
    {
        return this.max;
    }
    
    public double getVMax()
    {
        return this.vMax;
    }
    
    protected boolean isInSpace(double d)
    {
        return (d> -this.max) && (d< this.max);
    }
    
    protected double max;
    protected double min;
    protected double vMax;
}

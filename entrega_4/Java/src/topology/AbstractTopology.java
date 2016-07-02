/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topology;

import main_src.Particle;
import java.util.ArrayList;

/**
 *
 * @author Geraldo e Iago
 */
public abstract class AbstractTopology implements ITopology
{
    protected ArrayList allFits;//double
    
    @Override
    public void init(int size)
    {
        this.allFits = new ArrayList(size);
        for(int i=0; i<size; i++)
        {
            this.allFits.add(Double.MAX_VALUE);
        }
    }
    
    @Override
    abstract public void setGBest(double val, ArrayList<Particle> vec);

    @Override
    public void setFitAt(int pos, double fit)
    {
        if(fit<(double)this.allFits.get(pos))
        {
            this.allFits.set(pos, fit);
        }
    }
    
    @Override
    abstract public double getBest();
}

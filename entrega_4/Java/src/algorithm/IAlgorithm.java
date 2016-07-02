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
public interface IAlgorithm {
    public void init();
    public double fitness(Particle part, ArrayList<Particle> others);
    
    public double getInitialBest();
    
    public double getMin();
    public double getMax();
    public double getVMax();
}

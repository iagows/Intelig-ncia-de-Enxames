/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithm;

/**
 *  Escolhe o algoritmo a ser usado
 * @author Geraldo e Iago
 */
public class AlgorithmFactory {
    private IAlgorithm alg;
    public AlgorithmFactory(AlgorithmEnum type)
    {
        switch(type)
        {
            default:
            case PROJECT:
                this.alg = new ProjectAlgorithm();
                break;
        }
    }
    
    public IAlgorithm get()
    {
        return this.alg;
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package topology;

/**
 *
 * @author Geraldo e Iago
 */
public class TopologyFactory
{
    private ITopology top;
    public TopologyFactory(TopologyEnum tEnum)
    {
        switch(tEnum)
        {
            default:
            case STAR:
                this.top = new TopologyStar();
                break;
        }
    }
    
    public ITopology get()
    {
        return this.top;
    }
}

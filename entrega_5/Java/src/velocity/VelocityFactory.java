/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package velocity;

/**
 *
 * @author Geraldo e Iago
 */
public class VelocityFactory
{
    private IVelocity vel;
    public VelocityFactory(VelocityEnum vEnum)
    {
        switch(vEnum)
        {
            default:
            case NORMAL:
                vel = new VelocityNormal();
                break;
            case CLERC:
                vel = new VelocityClerc();
                break;
        }
    }
    
    public IVelocity get()
    {
        return this.vel;
    }
}

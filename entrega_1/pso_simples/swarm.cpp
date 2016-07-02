#include "swarm.h"

#include <cstdlib>
#include <math.h>
Swarm::Swarm(int partAmount, int dimAmount, int maxEpoch,
             TopologyFactory::TOPOLOGY top, AlgorithmFactory::ALGORITHM alg, VelocityFactory::TYPE velType)
{
    this->particleAmount = partAmount;
    this->dimensionAmount = dimAmount;
    this->maxEpoch = maxEpoch;

    AlgorithmFactory af(alg);
    this->algorithm = af.get();

    TopologyFactory tf(top);
    this->topology = tf.get();
    this->topology->init(partAmount);

    VelocityFactory vf(velType);
    this->velocity = vf.get();

    this->ran = new IagoRandom();

    initClerc();
}

Swarm::~Swarm()
{
    for(unsigned int i=0, size = this->particles->size(); i<size; ++i)
    {
        delete this->particles->at(i);
    }

    delete this->particles;
    delete this->ran;
    delete this->algorithm;
    delete this->topology;
    delete this->velocity;
}

std::vector<double> *Swarm::psoAlg()
{
    std::vector<double>* _outputFit = new std::vector<double>();
    //inicializando variáveis e partículas
    this->initialize();

    int size = this->particles->size();
    do
    {
        //vai parar se chegar no limite de epoch
        for(int i=0; i<size; ++i)
        {
            Particle *current = this->particles->at(i);
            double fit = this->algorithm->fitness(current, size);
            if(fit < current->getFitness())
            {
                current->setFitness(fit);
                current->setPBest(current->getData());//clona o vetor atual para pBest
            }
            this->topology->addFit(i, fit);
        }

        this->topology->updateBest(this->particles);
        _outputFit->push_back(this->topology->getBest());

        //para todas partículas
        for(int i=0; i<size; ++i)
        {
            Particle* current = this->particles->at(i);
            //atualiza o best da partícula
            this->topology->setBest(i, this->particles);
            for(int j=0; j<this->dimensionAmount; ++j)
            {
                this->calculateVelocityW(current, j);
                this->updatePosition(current, j);
            }
        }
        epoch++;
    }
    while(this->epoch < this->maxEpoch);
    return _outputFit;
}

void Swarm::initialize()
{
    this->epoch = 0;
    this->done = false;
    //this->bestFitness = RAND_MAX;

    this->algorithm->init(this->rangeMin, this->rangeMax, this->maxVelocity);

    this->particles = new std::vector<Particle*>();

    //criando as partículas
    for(int i=0; i<this->particleAmount; ++i)
    {
        Particle* p = new Particle(this->dimensionAmount);
        //criando valores para as dimensões
        for(int j=0; j<dimensionAmount; ++j)
        {
            //inicializando dentro dos limites
            int randomVal = ran->randRange(this->rangeMin, this->rangeMax);
            p->setData(j, randomVal);
            this->randomSpeed(p);
        }
        p->setPBest(p->getData());
        this->particles->push_back(p);
    }
}

void Swarm::calculateVelocity(Particle *part, int pos)
{
    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = (part->getVelocity(pos) +
                           (c1 * rand1 * (part->getPBest(pos) - part->getData(pos))) +
                           (c2 * rand2 * (part->getGBest()->at(pos) - part->getData(pos))));

    //clamping
    if(velocity > this->maxVelocity)
        velocity = this->maxVelocity;
    if(velocity < -this->maxVelocity)
        velocity = -this->maxVelocity;
    part->setVelocity(pos, velocity);
}

void Swarm::calculateVelocityW(Particle *part, int pos)
{
    double w = 0.8;
    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = w * (part->getVelocity(pos) +
                           (c1 * rand1 * (part->getPBest(pos) - part->getData(pos))) +
                           (c2 * rand2 * (part->getGBest()->at(pos) - part->getData(pos))));

    //clamping
    if(velocity > this->maxVelocity)
        velocity = this->maxVelocity;
    if(velocity < -this->maxVelocity)
        velocity = -this->maxVelocity;
    part->setVelocity(pos, velocity);
}

void Swarm::calculateVelocityDec(Particle *part, int pos)
{
    //w inicial
    double w = 0.9;
    //w final
    double endW = 0.4;

    //tamanho da reduçao por iteraçao
    double wStep = endW/this->maxEpoch;

    //w atual apos reduçao por iteraçoes
    double currentW = w - (epoch*wStep);

    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = currentW*part->getVelocity(pos) +(
                                 (c1 * rand1 * (part->getPBest(pos) - part->getData(pos))) +
                                 (c2 * rand2 * (part->getGBest()->at(pos) - part->getData(pos)))
                );

    //clamping
    if(velocity > maxVelocity)
        velocity = maxVelocity;

    if(velocity < -maxVelocity)
        velocity = -maxVelocity;

    part->setVelocity(pos, velocity);
}


void Swarm::initClerc()
{
    this->_c1 = ran->randRange(1,4);
    _c2 = 4.1 - _c1;
    this->_phi = _c1 + _c2;

    double root = sqrt((_phi*_phi)-(4*_phi));
    double bot = 2 - _phi - root;
    if(bot < 0) bot = -bot;
    _X = 2/bot;
}

void Swarm::calculateVelocityC(Particle *part, int pos)
{
    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = _X*(part->getVelocity(pos) +
                                 (_c1 * rand1 * (part->getPBest(pos) - part->getData(pos))) +
                                 (_c2 * rand2 * (part->getGBest()->at(pos) - part->getData(pos))));

    part->setVelocity(pos, velocity);
}

void Swarm::updatePosition(Particle *part, int pos)
{
    double vel = part->getVelocity(pos);//velocidade já atualizada
    double oldPos = part->getData(pos);

    part->setData(pos, vel + oldPos);
}

void Swarm::randomSpeed(Particle *part)
{
    int size = this->dimensionAmount;
    for(int i=0; i<size; ++i)
    {
        double randSpeed = ran->randRange(-4,4);
        if(randSpeed==0)randSpeed++;
        part->setVelocity(i, randSpeed);
    }
}

double Swarm::sumVector(std::vector<double> *v)
{
    double out = 0;
    for(double d : *v)
        out += d;
    return out;
}

/*
 * \file Reference.h
 * \brief initialisation des différentes classes d'exception
 * \author Emilio Lemus
 * \date 2022-11-28
 *
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <string>
#include <stdexcept>

class ReferenceException : public std::runtime_error
{
public:
  ReferenceException (const std::string& p_raison);
};

class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException (const std::string& p_raison);

};

class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException (const std::string& p_raison);

};


#endif /* REFERENCEEXCEPTION_H */


"""
Demonstration of hybrid properties in SQLAlchemy. Hybrid properties are like
synthetic columns. You can query the table using these values, but they aren't
actual columns in the table. They are just calculated from real columns.

Hybrid methods are also demonstrated. These are similar. You can use them to
query, but you need to provide arguments rather than just getting a value that
is a property of the object (i.e., something calculated from the object data)
"""

from sqlalchemy import Column, Integer, String, create_engine, func
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker, aliased
from sqlalchemy.ext.hybrid import hybrid_property, hybrid_method

Base = declarative_base()


class Person(Base):
    __tablename__ = 'people'

    id = Column(Integer, primary_key=True)
    firstname = Column(String, nullable=False)
    lastname = Column(String, nullable=False)

    @hybrid_property
    def fullname(self):
        # return '{0} {1}'.format(self.firstname, self.lastname)
        # return '{0} {1}'.format(str(self.firstname), str(self.lastname))
        return self.firstname + ' ' + self.lastname

if __name__ == '__main__':
    engine = create_engine('sqlite:///:memory:', echo=True)

    Base.metadata.create_all(engine)

    SessionFactory = sessionmaker(bind=engine)
    session = SessionFactory()

    alice = Person(firstname='Alice', lastname='Anderson')
    bob = Person(firstname='Bob', lastname='Barr')

    session.add_all([alice, bob])

    me = session.query(Person). \
         filter(Person.firstname == 'Alice'). \
         one_or_none()
    if me:
        print('===========> ' + me.lastname)
        print('===========> ' + me.fullname)
    else:
        print('===========> Not found!')

    me = session.query(Person). \
         filter(Person.fullname == 'Bob Barr'). \
         one_or_none()
    if me:
        print('===========> ' + me.lastname)
        print('===========> ' + me.fullname)
    else:
        print('===========> Not found!')
        

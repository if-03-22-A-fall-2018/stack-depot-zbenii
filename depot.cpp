#include "depot.h"
#include "stack.h"

struct DepotImplementation
{
    Stack depotStack;
};

Depot create_depot()
{
    Depot d = (struct DepotImplementation *)smalloc(sizeof(struct DepotImplementation));
    d->depotStack = create_stack();
    return d;
}

void delete_depot(Depot depot)
{
    delete_stack(depot->depotStack);
    sfree(depot);
}

void push_depot(Depot depot, Product *product)
{
    push_stack(depot->depotStack, product);
}

int get_count(Depot depot)
{
    int count = get_count(depot->depotStack);
    int products=count / STACK_SIZE_LIMIT;

    if(count%STACK_SIZE_LIMIT>0)
    {
      return products+1;
    }
    else
    {
      return products;
    }

    return 0;
}

Product *pop_depot(Depot depot)
{
    return (Product *)pop_stack(depot->depotStack);
}

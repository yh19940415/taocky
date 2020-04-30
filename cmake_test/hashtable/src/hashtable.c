#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

size_t HashFuncDefault(KeyType key)
{
    return key%HashMaxSize;
}
////////////////////////////////////////////////////////////////////////////////////
void HashTableInit(HashTable* ht)
{
    if (ht == NULL)    //非法输入
        return;
    ht->size = 0;
    ht->hashfunc = HashFuncDefault;
    for (size_t i = 0; i < HashMaxSize; i++)
    {
        ht->data[i].key = 0;
        ht->data[i].stat = Empty;
        ht->data[i].value = 0;
    }
}
//哈希表的插入 ,插入成功返回1，插入失败返回0
int HashTableInsert(HashTable* ht, KeyType key, ValueType value)
{
    if (ht == NULL)
        return 0;
    if (ht->size >= HashMaxSize*LoadFactor)   //当哈希表的size超出了负载
        return 0;
    //1.先根据哈希函数将key转换，求得key在哈希表中的下标
    size_t cur = ht->hashfunc(key);
    //2.判断当前下标是否被占用
    while (1)
    {
        if (ht->data[cur].key == key)     //用于保证不会用重复的数字存入哈希表
            return 0;
        if (ht->data[cur].stat != Valid)
        {
            ht->data[cur].key = key;
            ht->data[cur].value = value;
            ht->data[cur].stat = Valid;
            ht->size++;
            return 1;
        }
        cur++;
    }
}

//哈希表的查找 找到返回1，没找到返回0
int HashTableFind(HashTable* ht, KeyType key, ValueType* value)
{
    if (ht == NULL)
        return 0;
    //通过哈希函数找到key所对应的下标
    size_t offset=ht->hashfunc(key);
    //若当前下标所对应的值正好是key并且当前的状态必须为valid才返回
    if (ht->data[offset].key == key&&ht->data[offset].stat==Valid)
    {
        *value = ht->data[offset].value;
        return 1;
    }
    //若当前下标所对应的值不是key，则继续向后进行查找，直到找到stat等于empty
    else
    {
        while (ht->data[offset].stat != Empty)
        {
            if (ht->data[offset].key != key)
            {
                offset++;
                //判断是否下标已超出最大值
                if (offset >= HashMaxSize)
                    offset = 0;
            }
            else
            {
                if (ht->data[offset].stat == Valid)
                {
                    *value = ht->data[offset].value;
                    return 1;
                }
                else
                    offset++;
            }
        }
            return 0;
    }
}
//删除节点
int HashTableFindCur(HashTable* ht, KeyType key, size_t* cur)
{
    if (ht == NULL)
        return 0;
    for (size_t i = 0; i < HashMaxSize; i++)
    {
        if (ht->data[i].key == key && ht->data[i].stat == Valid)
        {
            *cur = i;
            return 1;
        }
    }
    return 0;
}
void HashRemove(HashTable* ht, KeyType key)
{
    if (ht == NULL)  //非法输入
        return;
    //先用find函数查找key是否存在
    ValueType value = 0;
    size_t cur = 0;                      //得到要删除元素的下标
    int ret=HashTableFindCur(ht,key,&cur);//通过find函数得到key是否存在在哈希表中
    if (ret == 0)
        return;
    else
    {
        ht->data[cur].stat = Invalid;
        ht->size--;
    }
}

int HashEmpty(HashTable* ht)
{
    if (ht == NULL)
        return 0;
    else
        return ht->size > 0 ? 1 : 0;
}

//求哈希表的大小
size_t HashSize(HashTable* ht)
{
    if (ht == NULL)
        return 0;
    return ht->size->data[i].stat=Empty;//HashElem
        ht->data[i].key = 0;
        ht->data[i].value = 0;

    ht->size = 0;
}

void HashPrint(HashTable* ht,const char* msg)         //打印哈希表
{
    if (ht == NULL || ht->size == 0)
        return;
    printf("%s\n", msg);
    for (size_t i = 0; i < HashMaxSize; i++)
    {
        if (ht->data[i].stat != Empty)
            printf("[%d]  key=%d  value=%d  stat=%d\n", i, ht->data[i].key,
            ht->data[i].value, ht->data[i].stat);
    }
}


void testHashTableInsert(HashTable* ht)
{
    __TestHead__;
    HashTableInit(ht);
    HashTableInsert(ht, 1, 1);
    HashTableInsert(ht, 2, 2);
    HashTableInsert(ht, 1001, 1001);
    HashTableInsert(ht, 1002, 1002);
    HashTableInsert(ht, 10001, 10001);
    HashTableInsert(ht, 1002, 1002);
    HashPrint(ht, "插入四个元素");
}

void testHashTableFind(HashTable* ht)
{
    __TestHead__;
    HashTableInit(ht);
    HashTableInsert(ht, 1, 1);
    HashTableInsert(ht, 2, 2);
    HashTableInsert(ht, 1001, 1001);
    HashTableInsert(ht, 102, 102);
    HashTableInsert(ht, 10001, 10001);
    HashTableInsert(ht, 1002, 1002);
    ValueType value = 0;
    int ret = HashTableFind(ht, 1002, &value);
    printf("ret: expect=1    actual=%d\nvalue: expect=1002    actual=%d\n", ret,value);
}

void testHashRemove(HashTable* ht)
{
    __TestHead__;
    HashTableInit(ht);
    HashTableInsert(ht, 1, 1);
    HashTableInsert(ht, 2, 2);
    HashTableInsert(ht, 1001, 1001);
    HashTableInsert(ht, 102, 102);
    HashTableInsert(ht, 10001, 10001);
    HashTableInsert(ht, 1002, 1002);
    HashPrint(ht, "插入完成后");
    HashRemove(ht, 2);
    HashPrint(ht, "删除一个元素");
    HashTableInsert(ht, 100001,100001);
    HashPrint(ht, "插入一个元素");

}

void test()
{
    HashTable ht;
    HashTableInit(&ht);
    testHashTableInsert(&ht);
    testHashTableFind(&ht);
    testHashRemove(&ht);
}


int main(int argc, char **argv)
{

  test();

  return 0;
}

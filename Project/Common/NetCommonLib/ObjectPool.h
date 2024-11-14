//==================================================================================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
// 
// CObjectPool
// - 오브젝트 풀(pool)
//==================================================================================================

#pragma once

#include "pch.h"

#define OBJECT_POOL_DEFAULT_CHUNK_SIZE 100

template<typename T>
class CObjectPool
{
	concurrency::concurrent_vector<T*> chunks_;
	BYTE* current_ptr_;
	UINT chunk_size_;
	std::mutex mutex_;

public:
	CObjectPool()
	{
		chunks_.clear();

		chunk_size_ = OBJECT_POOL_DEFAULT_CHUNK_SIZE;

		_Extend();
	}

	CObjectPool( unsigned int _chunk_size )
	{
		chunks_.clear();

		chunk_size_ = _chunk_size;

		_Extend();
	}

	virtual ~CObjectPool()
	{
		Release();
	}

public:
	T* Alloc()
	{
		std::lock_guard<std::mutex> lock( mutex_ );

		if( nullptr == current_ptr_ )
		{
			_Extend();
		}

		BYTE* alloc_ptr = current_ptr_;

		current_ptr_ = *( BYTE** )alloc_ptr;

		ZeroMemory( alloc_ptr, sizeof( T ) );

		return ( T* )alloc_ptr;
	}

	void Dealloc( T** _dealloc_ptr )
	{
		std::lock_guard<std::mutex> lock( mutex_ );

		ZeroMemory( *_dealloc_ptr, sizeof( T ) );

		*( ( BYTE** )( *_dealloc_ptr ) ) = current_ptr_;

		current_ptr_ = ( BYTE* )( *_dealloc_ptr );

		( *_dealloc_ptr ) = nullptr;
	}

	void Release()
	{
		std::lock_guard<std::mutex> lock( mutex_ );

		for( auto header : chunks_ )
		{
			delete[] header;
		}

		chunks_.clear();

		current_ptr_ = nullptr;
	}

	unsigned long Size()
	{
		return ( sizeof( T ) * chunk_size_ * chunks_.size() );
	}

private:
	void _Extend()
	{
		T* header = new T[ chunk_size_ ];
		ZeroMemory( header, sizeof( header ) );

		//< 
		chunks_.push_back( header );

		//<
		BYTE** curr_ptr = ( BYTE** )header;
		BYTE* next_ptr = ( BYTE* )header;

		for( UINT i = 0; i < ( chunk_size_ - 1 ); i++ )
		{
			next_ptr += sizeof( T );

			( *curr_ptr ) = next_ptr;

			curr_ptr = ( BYTE** )next_ptr;
		}

		( *curr_ptr ) = nullptr;

		current_ptr_ = ( BYTE* )header;
	}
};